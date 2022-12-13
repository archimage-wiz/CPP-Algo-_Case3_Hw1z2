#include <iostream>
#include <vector>


int BooksOversize(std::vector<int> _arr, int _oversize) { // get count of books is bigger than _oversize val

    int left_bone = -1;
    int right_bone = _arr.size();
    int cur_pos = _arr.size() / 2;
    while (right_bone - left_bone > 1) {
        if (_oversize < _arr[cur_pos]) {
            right_bone = cur_pos;
        } else {
            left_bone = cur_pos;
        }
        cur_pos = (left_bone + right_bone) / 2;
    }
    if (cur_pos == 0 && _arr[cur_pos] > _oversize) { 
        return _arr.size();
    }
    if (cur_pos == _arr.size()-1 && _arr[cur_pos] < _oversize) {
        return 0;
    }
    return _arr.size() - (cur_pos + 1);
}


int main() {

    int test_arr[] = { -1, 13, 14, 32, 60, 72, 73};
    std::vector<int> arr = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };

    for (auto i : test_arr)
    {
        std::cout << i << " " << BooksOversize(arr, i) << std::endl;
    }


    return 0;
}

