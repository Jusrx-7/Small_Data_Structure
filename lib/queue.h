//
// Created by xy on 1/6/24.
//
#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H
template<class DATA_TYPE , int SIZE>
class queue
{
    /*
     * used TEMPLATE for dynamic input data-type
     * Then used pinter and dynamic Memory allocation
     */
private:
    SHORT TOP = -1, size=SIZE, DOWN=0;
    DATA_TYPE * ptr;
public:
    queue()
    {
        ptr = new DATA_TYPE[SIZE];
    }
    ~queue()
    {
        delete ptr;
    }

    void PUSH(DATA_TYPE inp)
    {
        if (TOP == SIZE-1)
        {
            std::cout << " STACK Is FULL ."   << "\n";
        }
        else
        {
            ptr[TOP+1] = inp;
            TOP++;
        }
    }
    void FULL_PUSH()
    {
        SHORT temp;
        for (int i = 0; i < SIZE; ++i) {
            std::cout << "Value Of Element Number " << i+1 << " Will be : ";
            std::cin >> temp ;
            ptr[i] = temp;
            TOP++;
        }
    }
    void SHOW_STACK()
    {
        if (TOP == -1)
        {
            std::cout << "Nothing to SHOW, STACK is empty. \n";
        }else
        {
            for (int i = 0; i < SIZE; ++i)
            {
                std::cout << "Element NUMBER " << i+1  << " = "<< ptr[i]<<std::endl;
            }
        }
    }
    void POP()
    {
        if (DOWN == (TOP+1))
        {
            std::cout << "STACK in empty. \n";
        }else
        {
            SHORT temp;
            for (int i = 0; i < SIZE; ++i)
            {
                temp = ptr[i+1];
                ptr[i] = temp;
            }
            TOP--;
        }
    }
    void FREE()
    {
        if (DOWN == (TOP+1)){
            std::cout << "STACK Already empty . \n";
        }else
        {
            for (int i = 0; i < SIZE; ++i)
            {
                ptr[i] = 0 ;
            }
            TOP= -1;
        }
    }
    void IS_EMPTY()
    {
        if (TOP == -1)
        {
            std::cout << "Yes, It's empty" << "\n" ;
        }
    }
    void IS_FULL()
    {
        if(TOP == SIZE-1)
        {
            std::cout << "Yes, it's FULL\n";
        }else
        {
            std::cout << "NO, It's empty" << "\n" ;
        }
    }
    void RESIZE(int siz)
    {
        SHORT *ptr_resize = new DATA_TYPE[siz];
        for (int i = 0; i < size; ++i)
        {
            ptr_resize[i] = ptr[i]; // or => *(ptr_resize+i) = *(ptr+i);
            ++size;
        }
        delete ptr;
        ptr=ptr_resize ;
    }
};
#endif //DATA_STRUCTURE_QUEUE_H
