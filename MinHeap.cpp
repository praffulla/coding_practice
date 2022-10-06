// Online C++ compiler to run C++ program online
#include <iostream>
class MinHeap {
    
    int *harr;
    int size;
    int capacity;
    public:
    MinHeap(int cap) {
        size = 0;
        capacity = cap;
        harr = new int[cap];
    }
    
    int parent(int i) {
        return (i-1)/2;
    }
    
    void minHeapify(int i) {
        int smallest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l < size && harr[l] < harr[smallest]) {
            smallest = l;
        }
        
        if(r < size && harr[r] < harr[smallest]) {
            smallest = r;
        }
        
        if(i != smallest) {
            int t = harr[smallest];
            harr[smallest] = harr[i];
            harr[i] = t;
            minHeapify(smallest);
        }
    }
    
    int extractMin() {
        if(size <= 0) {
            printf("\n cannot extract more");
            return -1;
        }
        
        int res = harr[0];
        harr[0] = harr[size-1];
        size--;
        minHeapify(0);
        return res;
    }
    
    void printHeap() {
        for(int i = 0; i <size; i++) {
            printf("\t %d", harr[i]);
        }
        printf("\n");
    }
    
    void insertKey(int elem) {
        harr[size] = elem;
        size++;
        
        int i = size-1;
        while(i != 0 && harr[parent(i)] > harr[i]) {
            int t = harr[parent(i)];
            harr[parent(i)] = harr[i];
            harr[i] = t;
            
            i = parent(i);
        }
    }
};


int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    
    MinHeap *mH = new MinHeap(10);
    mH->insertKey(11);
    mH->insertKey(3);
    mH->insertKey(2);
    mH->insertKey(1);
    mH->insertKey(15);
    mH->insertKey(5);
    mH->insertKey(4);
    mH->insertKey(45);
    
    mH->printHeap();
    
    printf("\n extract min is %d", mH->extractMin());
    printf("\n extract min is %d", mH->extractMin());
    printf("\n extract min is %d", mH->extractMin());
    printf("\n extract min is %d", mH->extractMin());
    
    

    return 0;
}
