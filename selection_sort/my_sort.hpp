// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful



//void swap(int *xp, int *yp)
////{
    //int temp = *xp;
    //*xp = *yp;
    //*yp = temp;
//}

 
template <typename T>
void my_selection_sort(T begin, T end) {
    T cp = begin;
    while (cp != end)
    {
        T min = cp;
        T sto = cp;
        while (sto != end)
        {
            if (*min > *sto)
                min = sto;
            sto++;

        }
        
        auto check = *cp;
        *cp = *min;
        *min = check;
        cp++;
    }


}
