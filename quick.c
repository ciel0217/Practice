#include <stdio.h>
#include <stdlib.h> 
#define nm 100
int *num;

void q_sort( int left, int right)
{
    int pivot, l_hold, r_hold;

    l_hold = left;
    r_hold = right;
    pivot = num[left];
    while (left < right)
    {
        while ((num[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            num[left] = num[right];
            left++;
        }
        while ((num[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            num[right] = num[left];
            right--;
        }
    }
    num[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        q_sort(left, pivot-1);
    if (right > pivot)
        q_sort(pivot+1, right);
}



int main(){
    int  *quick;
	num = (int *)malloc(sizeof(int)*nm);
    quick=(int *)malloc(sizeof(int)*nm);

	for (int i = 0; i < nm; i++) {
		num[i] = rand()%nm+1;
	}

	for (int i = nm - 1; i >= 0; i--) {
		printf("%d,", num[i]);
	}
	printf("\n");
	q_sort(0, nm - 1);

	for (int i = nm-1; i >=0; i--) {
		printf("%d,", num[i]);
	}
	return 0;
}