class Node
{
public:
    Node *one;
    Node *zero;
};
class Trie
{
    Node *root;

public:
    Trie() { root = new Node(); }
    void insert(int n)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->zero == NULL)
                {
                    temp->zero = new Node();
                }
                temp = temp->zero;
            }
            else
            {
                if (temp->one == NULL)
                {
                    temp->one = new Node();
                }
                temp = temp->one;
            }
        }
    }
    int max_and(int value)
    {
        Node *temp = root;
        int current_ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;
            if (bit == 0)
            {
                if (temp->zero)
                {
                    temp = temp->zero;
                    current_ans += (1 << i);
                }
                else
                {
                    temp = temp->one;
                }
            }
            else
            {
                if (temp->one)
                {
                    temp = temp->one;
                    current_ans += (1 << i);
                }
                else
                {
                    temp = temp->zero;
                }
            }
        }
        return current_ans;
    }
};