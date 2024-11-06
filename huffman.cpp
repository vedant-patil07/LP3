#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (int i = 0; i < size; i++)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    cout << "\n*" << endl;
    cout << "\nHuffman Codes " << endl;
    printCodes(minHeap.top(), "");
}

int main()
{
    int n;
    cout << "\nEnter the number of characters : ";
    cin >> n;

    char *arr = new char[n];
    int *freq = new int[n];

    cout << "\nEnter the characters and their frequencies : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Characters " << i + 1 << ": ";
        cin >> arr[i];
        cout << "Frequency " << i + 1 << ": ";
        cin >> freq[i];
    }

    HuffmanCodes(arr, freq, n);

    return 0;
}