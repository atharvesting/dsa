#include "my_utils.h"
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

//ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//	if (list1 and !list2) return list1;
//	else if (!list1 and list2) return list2;
//	else if (!list1 and !list2) return nullptr;
//
//	if (list1->val > list2->val) {
//		ListNode* q = list1;
//		list1 = list2;
//		list2 = q;
//	}
//	ListNode* current_l1 = list1;
//
//	while (list2 != nullptr) {
//		while (current_l1->val < list2->val and current_l1->next != nullptr) {
//			if (current_l1->next->val > list2->val) break;
//			current_l1 = current_l1->next;
//		}
//		ListNode* temp_l1 = current_l1->next;
//		ListNode* temp_l2 = list2->next;
//		current_l1->next = list2;
//		list2->next = temp_l1;
//		list2 = temp_l2;
//		current_l1 = current_l1->next;
//	}
//	return list1;
//}

std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
    std::unordered_map<int, int> map1;
    std::unordered_map<int, int> map2;
    std::vector<int> result;
    int common{ 0 };
    for (size_t i = 0; i < A.size(); i++) 
    {
        auto an = A[i]; auto bn = B[i];
        map1[an] = 1; map2[bn] = 1;

        if (map1.find(bn) != map1.end()) {
            common++;
        }
        if (map2.find(an) != map2.end() && an != bn) {
            common++;
        }
        result.push_back(common);
    }
    return result;
}

// I did not take care of mid after removing the == condition.

int search(std::vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1, mid = 0;

    // Find the smallest value in the array
    while (l < h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] > nums[h]) l = mid + 1;
        else h = mid;
    }
    
    //std::cout << std::endl << nums[l] << " at index " << l << std::endl;
    
    // Now, l is the index to the smallest value in the array
    int modo = nums.size();
    h = l + modo;
    
    while (l <= h) 
    {
        mid = (l + (h - l) / 2);
        
        if (nums[mid % modo] == target) return mid % modo;

        else if (nums[mid % modo] > target) h = mid - 1;

        else l = mid + 1;
    }

    return -1;
}

int main() {

    std::vector<int> A = { -1 };

    for (const auto& n : A) {
        std::cout << search(A, -1) << std::endl;
    }

	return 0;
}