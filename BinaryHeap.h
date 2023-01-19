#include <iostream>


using namespace std;


template <typename T>
class BinaryHeap
{

    vector<T> node;
    int parent(int i) { return floor((i - 1) / 2); }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }


    void heapDown(int index)
    {
        int l = leftChild(index);
        int r = rightChild(index);
        int smallest = index;

        if(l < node.size() && data_cmp(node[l], node[index]) < 0 )
        {
            smallest = l;
        }
        if( r < node.size() && data_cmp(node[r], node[l]) < 0 )
        {
            smallest = r;
        }
        if (smallest != index)
        {
            swap(node[index], node[smallest]);
            heapDown(smallest);
        }
    }


    void heapUp(int index)
    {
        if(index == 0)
        {
            return;
        }

        int p = parent(index);

        if(data_cmp(node[p], node[index]) > 0)
        {
            swap(node[p], node[index]);
            heapUp(parent(index));
        }
    }

public:

    void addAtEnd(T data)
    {
        node.push_back(data);

        if (node.size() == 1)
            return;

        heapUp(node.size() - 1);
    }



    T deleteFirst()
    {
        if(node.size() == 0)
            abort();
        T del = node[0];
        node[0] = node[node.size() - 1];
        node.pop_back();

        heapDown(0);

        return del;
    }



    void clearNode()
    {
        while(! node.empty())
        {
            deleteFirst();
        }
    }

    void toStringHeap()
    {
        for(int i = 0; i < node.size(); i++)
        {
            cout << treeToString(node[i]) << endl;
        }
    }

    int(*data_cmp)(T, T);
    string(*treeToString)(T);

};
