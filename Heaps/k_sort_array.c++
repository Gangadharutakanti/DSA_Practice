#include<iostream>
#include<vector>
using namespace std;

class Sort{
    public:
        void kthsort(vector<int>&nums,int k){
            vector<int>min_heap(k+1,0);
            int size=0;
            for(int i=0;i<=k;i++){
                insert(min_heap,nums[i],size);
            }
            int z=0;
            for(int j=k+1;j<nums.size();j++){
                nums[z++]=min_heap[0];
                delete1(min_heap,size);
                insert(min_heap,nums[j],size);
            }
            while(size>0){
            nums[z++] = min_heap[0];
            delete1(min_heap,size);
            }
        }

        void delete1(vector<int>&vec,int &size){
            swap(vec[0],vec[size-1]);
            size--;
            heapify(vec,0,size);
        }

        void heapify(vector<int>&vec,int index,int &size){
            if(size==0||size==1){
                return ;
            }
            int li=2*index+1;
            int ri=2*index+2;
            int smallest=index;
            if(li<size&&vec[li]<vec[smallest]){
                smallest=li;
            }
            if(ri<size&&vec[ri]<vec[smallest]){
                smallest=ri;
            }
            if(smallest!=index){
                swap(vec[smallest],vec[index]);
                heapify(vec,smallest,size);
            }
        }

        void insert(vector<int>&vec,int num,int &size){
            vec[size]=num;
            int k=size;
            size++;
            while(k!=0&&vec[(k-1)/2]>vec[k]){
                swap(vec[(k-1)/2],vec[k]);
                k=(k-1)/2;
            }
        }
};


int main(){
    vector<int>nums={6,5,3,2,8,10,9};
    int k=2;
    Sort h;
    h.kthsort(nums,k);
    for(auto i:nums){
        cout<<i<<endl;
    }
    return 0;
}

