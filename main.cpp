/*
list и
unordered_set
1 Добавление элементов в начало list и вставка в
unordered_set.
2. Поиск элементов.
3. Удаление элементов из конца list и удаление из
unordered_set.
*/

#include <iostream>
#include <list>
#include <unordered_set>
#include <ctime>
int main()
{   
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    std::list<int> list;
    std::unordered_set<int> set;
    int n = 100000; // Количество элементов
    // Заполняем list и set рандомными элементами
    for (size_t i = 0; i < n; ++i) { 
        list.push_back(rand() % 100);
    }
    for (size_t i = 0; i < n;++i) {
        set.insert(rand() % 100);
    }
    // 1. Добавление элементов в начало list и вставка в unordered_set
    uint32_t start_time = clock();    
    for (size_t i = 0; i < n;++i) { // O(n)
        list.push_front(rand() % 100);
    }
    uint32_t end_time = clock();
    std::cout << "Добавление элементов в начало list: " << end_time - start_time << std::endl;
    start_time = clock();
    for (size_t i = 0; i < n;++i) { // O(N)
        set.insert(rand() % 100);
    }
    end_time = clock();
    std::cout << "Вставка элементов в set: " << end_time - start_time << std::endl;

    // 2. Поиск элементов
    start_time = clock();
    for (size_t i = 0; i < n; ++i) {
        find(list.begin(), list.end(), rand() % 100); // O(n)
    }
    end_time = clock();
    std::cout << "Поиск элементов в list: " << end_time - start_time << std::endl;
    start_time = clock();
    for (size_t i = 0; i < n; ++i) {
        set.find(rand() % 100); // O(log n)
    }
    end_time = clock();
    std::cout << "Поиск элементов в set: " << end_time - start_time << std::endl;
    // 3. Удаление элементов из конца list и удаление из unordered_set
    start_time = clock();
    for (size_t i = 0; i < n; ++i) {
        list.pop_back(); // O(1)
    }
    end_time = clock();
    std::cout << "Удаление элементов из конца list: " << end_time - start_time << std::endl;
    start_time = clock();
    for (size_t i = 0; i < n; ++i) {
        set.erase(rand()%100); // O(log n)
    }
    end_time = clock();
    std::cout << "Удаление элементов из unordered_set: " << end_time - start_time << std::endl;
    return 0;
}
