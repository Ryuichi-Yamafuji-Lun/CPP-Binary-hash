//hash implementation
#include <iostream>
using namespace std;

int n = 0;
//hashed item
struct hash_item {
    int key;
    int value;
};

//hash table
struct hash_table {
    int flag;
    struct hash_item *data;
};

struct hash_table *array;

//initialize array
void init_array(int n) {
    for (int i = 0; i < n; i++) {
        ::array[i].flag = 0;
        ::array[i].data = NULL;
    };
};

//hash the key
int hashed_key(int key, int n) {
    return (key % n);
};

//insert value
void insert (int key, int n, int delta, int size) {
    //get hashed key
    int index = hashed_key(key, n);
    int i = index;
    //memory allocate
    struct hash_item *item = (struct hash_item*)malloc(sizeof(struct hash_item));
    item->key = index;
    item->value = key;
    if (size == n) {
        cout << "hash table is full" << endl;
        return;
    }
    //check if key already has a value
    while (::array[i].flag == 1) {
        i += delta;
        if (i == n) {
            i -= n;
        } else if (i > n) {
            i -= n;
        };
    }
    ::array[i].flag = 1;
    ::array[i].data = item;
    size++;
    return;
};

//display
void display(int n) {
    for (int i = 0; i < n; i++) {
        struct hash_item *current = (struct hash_item*)::array[i].data;
        if (current == NULL) {
            cout << "Key ("<< i << ") is empty" << endl;
        } else {
            cout << "Key (" << i << ") has value:" << current->value << endl;
        }
    }
};


int main(void) {
    //assigning bucket size (n) & Delta
    int delta, key, size, input = 0;
    cout << "Bucket size: ";
    cin >> n;
    cout << endl << "Delta: ";
    cin >> delta;

    //initialize the array
    ::array = (struct hash_table*)malloc(n * sizeof(struct hash_table*));
    init_array(n);

    //user input
    while(1) {
        //ask user for key
        cout << "\nLinear Probing Hash Table Implementation" << endl;
        cout << "Choose one of the Following:" << endl;
        cout << "1. Insert Data \n2. Display Hash Table \n3. exit\noption: ";
        cin >> input;
        //case option
        switch(input) {
            case 1:
                cout << "Key: ";
                cin >> key;
                insert(key, n, delta, size);
                break;
            case 2:
                display(n);
                break;
            case 3:
                return 0;
            default:
                cout << "Wrong input" << endl;
                break;

        };
    };
}