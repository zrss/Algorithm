// [start, end)
// 返回kth数的下标
int findKthNumber(vector<int>& nums, int start, int end, int kth) {
	if (start < end) {
		int mid = partition(nums, start, end);
		if (mid + 1 == kth) {
			return mid;
		}
		else if (mid + 1 < kth) {
			return findKthNumber(nums, mid + 1, end, kth);
		}
		else {
			return findKthNumber(nums, start, mid, kth);
		}
	}

	return -1;
}

// 返回pivot值的index
int partition(vector<int>& nums, int start, int end) {
	// 取 end - 1 作为 pivot 值
	int pivot = nums[end - 1];

	int i = start - 1; // < x 部分的最后一个元素位置
	int j = start; // > x 部分的最后一个元素位置

	while (j < end - 1) {
		if (nums[j] < pivot) {
			++i;
			swap(nums[i], nums[j]);
		}
		++j;
	}

	swap(nums[i + 1], nums[end - 1]);

	return i + 1;
}