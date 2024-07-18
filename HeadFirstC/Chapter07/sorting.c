#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_scores(const void* score_a, const void* score_b)
{
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return a - b;
}

int compare_scores_desc(const void* score_a, const void* score_b)
{
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return b - a;
}

typedef struct {
	int width;
	int height;
} rectangle;

int compare_areas(const void* a, const void* b)
{
	rectangle* rectA = (rectangle*)a;
	rectangle* rectB = (rectangle*)b;
	int areaA = rectA->width * rectA->height;
	int areaB = rectB->width * rectB->height;
	return areaA - areaB;
}

int compare_areas_desc(const void* a, const void* b)
{
	return compare_areas(b, a);
}

int compare_names(const void* a, const void* b)
{
	char** strA = (char**)a;
	char** strB = (char**)b;
	return strcmp(*strA, *strB);
}

int compare_names_desc(const void* a, const void* b)
{
	return compare_names(b, a);
}

int main(int argc, char* argv[])
{
	int scores[] = { 543,323,32,554,11,3,112 };
	qsort(scores, 7, sizeof(int), compare_scores);
	//qsort(scores, 7, sizeof(int), compare_scores_desc);

	rectangle rects[] = {
		{ 5, 5 },
		{ 6, 6 },
		{ 7, 7 }
	};
	//qsort(rects, 3, sizeof(rectangle), compare_areas);
	qsort(rects, 3, sizeof(rectangle), compare_areas_desc);

	char* names[] = {
		"John",
		"Nancy",
		"Harry",
		"Aaron"
	};
	//qsort(names, 4, sizeof(char*), compare_names);
	qsort(names, 4, sizeof(char*), compare_names_desc);

	return 0;
}