#include "sort.hpp"

static void buble_sort(std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        for (size_t j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void sort1(std::vector<int>& vec) {
    buble_sort(vec);
}

DWORD WINAPI thread_sort(LPVOID arg)
{
    ThreadArg* thread_arg = static_cast<ThreadArg*>(arg);
    buble_sort(*thread_arg->vec);
    return 0;
}


void sort2(std::vector<int>& vec)
{
    size_t mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    ThreadArg left_arg = { &left };
    ThreadArg right_arg = { &right };

    HANDLE thread1 = CreateThread(nullptr, 0, thread_sort, &left_arg, 0, nullptr);
    HANDLE thread2 = CreateThread(nullptr, 0, thread_sort, &right_arg, 0, nullptr);

    if (!thread1 || !thread2)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    CloseHandle(thread1);
    CloseHandle(thread2);

    vec.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vec));
}



