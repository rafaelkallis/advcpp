//
// Created by Rafael Kallis on 25.10.16.
//

template<typename T,
        typename in_container1,
        typename in_container1_control,
        typename in_container2 = in_container1,
        typename in_container2_control = in_container1_control,
        typename out_container = in_container1,
        typename out_container_control = in_container1_control>
class container_merger {
public:
    static void merge(in_container1 &in1, in_container2 &in2, out_container &out) {
        T val_1, val_2;
        while ((val_1 = in_container1_control::pop(in1))) {
            out_container_control::push(out, val_1);
        }
        while ((val_2 = in_container2_control::pop(in2))) {
            out_container_control::push(out, val_2);
        }
    }
};