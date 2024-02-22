#ifndef DS_SotrAlg_H
#define DS_SortAlg_H
#include <vector>
#include <string>

class SortingStrategy {
public:
    virtual ~SortingStrategy();

    virtual void sort(std::vector<int>& vec) const = 0;
};


class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& vec) const override;
};


class InsertionSort : public SortingStrategy {
public:
    void sort(std::vector<int>& vec) const override;
};


class SelectionSort : public SortingStrategy {
public:
    void sort(std::vector<int>& vec) const override;

};


class FileHandler {
public:
    static std::vector<int> readArrayFromFile(const std::string& filename); 
    static void addArrayToFile(const std::string& filename, const std::vector<int>& vec);
};


class SortingApplication {
private:
    SortingStrategy* sortingAlgorithm;
    FileHandler fileHandler;

public:
    SortingApplication();
    ~SortingApplication();

    void getUserInput();

private:
    void selectSortingAlgorithm();
};


#endif //DS_SortAlg_H
