#include <stdio.h>
#include <malloc.h>

/**
 *
 * @param numbers array
 * @param low min range
 * @param high max index
 * @param value
 * @return Returns index of searched value using binary search
 * If the value doesnt exist in the array the returned value will be -1.
 */
int search(int numbers[], int low, int high, int value) 
{

//    if (low==high) {
//        return -1;
//    }
//    if (low==high) {
//        return (low+high)/2;
//    }
    if (low <= high) {


        int mid = (low + high) / 2;

        if (value < numbers[mid]) { // CHECK LEFT
            int find = search(numbers, low, mid - 1, value);
            return find;
        } else if (value > numbers[mid]) { // CHECK RIGHT
            int find = search(numbers, mid + 1, high, value);
            return find;
        } else {
            return mid;
        }
    }
    return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}