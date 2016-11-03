import java.lang.reflect.Array;
import java.util.*;

interface Matcher<E> {
    boolean match(E elem);
}

interface Finder<E> {
    default E findIf(Iterator<E> it, Matcher<E> matcher) {

        while (it.hasNext()) {
            E elem = it.next();
            if (matcher.match(elem)) return elem;
        }
        return null;
    }
}

public class Main {


    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        Random rand = new Random();
        rand.setSeed(System.currentTimeMillis());

        final int max_n = 10000000;

        for (int i = 0; i < max_n; i++) {
            list.add(rand.nextInt(max_n));
        }
        long startTime = System.currentTimeMillis();
        Integer found = new Finder<Integer>() {
        }.findIf(list.iterator(), elem -> elem == 94);

        System.out.println(found != null ? "found match!" : "no match found.");
        System.out.println(System.currentTimeMillis() - startTime + "ms needed");

        int[] random_matches = new int[500];
        for(int i =0; i< 500; ++i) random_matches[i] = rand.nextInt(max_n);

        Stack<Long> deltas = new Stack<>();

        // optimized using Java 8's Stream API (faster than C++'s find_if, Macbook Pro 2015 - i7 4980HQ - 16 GB Random Mem)
        for (int i = 0; i < 500; ++i) {
            long startTimeFaster = System.currentTimeMillis();
            int finalI = i;
            Optional<Integer> match = list.parallelStream().filter(integer -> integer == random_matches[finalI]).findFirst();
            if (match.isPresent()) deltas.push(System.currentTimeMillis() - startTimeFaster);
        }

        long mean = 0;
        long size = deltas.size();
        while(!deltas.isEmpty()){
            mean += deltas.pop();
        }
        System.out.println("mean = " + (double) mean / size + "ms");
    }

    static class Tuple<T1, T2> {
        T1 key;
        T2 value;

        Tuple(T1 key, T2 value) {
            Tuple.this.key = key;
            Tuple.this.value = value;
        }
    }
}

