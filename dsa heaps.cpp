#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }
            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int powerLevel) {
        heap.push_back(powerLevel);
        std::cout << "Adding alien with power level " << powerLevel << " to the Max-Heap!" << std::endl;
        heapifyUp(heap.size() - 1);
        displayHeap();
    }

    void deleteRoot() {
        if (heap.empty()) {
            std::cout << "The Max-Heap is empty!" << std::endl;
            return;
        }
        std::cout << "Removing the strongest alien with power level " << heap[0] << " from the Max-Heap!" << std::endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        displayHeap();
    }

    void heapify(std::vector<int>& arr) {
        heap = arr;
        int startIdx = (heap.size() / 2) - 1;
        for (int i = startIdx; i >= 0; --i) {
            heapifyDown(i);
        }
        std::cout << "Heapifying the array: ";
        for (int powerLevel : arr) {
            std::cout << powerLevel << " ";
        }
        std::cout << std::endl;
        displayHeap();
    }

    void displayHeap() {
        std::cout << "Current Max-Heap: ";
        for (int powerLevel : heap) {
            std::cout << powerLevel << " ";
        }
        std::cout << std::endl;
        visualizeHeap();
    }

    void visualizeHeap() {
        std::cout << "Max-Heap Visualization:" << std::endl;
        int level = 0;
        int index = 0;
        while (index < heap.size()) {
            int levelNodes = 1 << level; // 2^level
            for (int i = 0; i < levelNodes && index < heap.size(); ++i) {
                std::cout << std::setw(4) << heap[index++];
            }
            std::cout << std::endl;
            level++;
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;

    // Task 1: Insert aliens
    maxHeap.insert(80); // Zorblax
    maxHeap.insert(70); // Quarx
    maxHeap.insert(60); // Blip
    maxHeap.insert(90); // Gorg

    // Task 2: Delete the root
    maxHeap.deleteRoot();
    maxHeap.deleteRoot();
    maxHeap.deleteRoot();
    maxHeap.deleteRoot();

    // Task 3: Heapify an array
    std::vector<int> powerLevels = {45, 20, 65, 10, 85, 30, 75};
    maxHeap.heapify(powerLevels);

    return 0;
}
