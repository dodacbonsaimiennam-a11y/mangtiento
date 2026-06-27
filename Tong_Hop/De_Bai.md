# BÁO CÁO CHUYÊN MÔN: 5 BÀI TẬP TỔNG HỢP KIỂM TRA ĐÁNH GIÁ

---

## MỨC ĐỘ 1: NHẬN BIẾT & THÔNG HIỂU

### Bài 1: TỔNG ĐOẠN TĨNH CỦA CHUỖI CUNG ỨNG (STATIC RANGE SUM)

**Tên file chương trình:** `BAI1.CPP` hoặc `BAI1.PY`
**File dữ liệu vào:** `BAI1.INP`
**File kết quả ra:** `BAI1.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [CSES Task 1646: Static Range Sum Queries](https://cses.fi/problemset/task/1646).

Trong kỹ thuật xử lý tín hiệu số, độ nhiễu loạn của tín hiệu cần được đo đạc liên tục qua từng khoảnh khắc thời gian. Bài toán tra cứu tổng tín hiệu trong một băng tần (từ tần số $L$ đến $R$) yêu cầu sử dụng Mảng tiền tố để lọc và đánh giá cường độ khuếch đại của tín hiệu. Đây là nền tảng cơ bản nhất của kỹ thuật Mảng tiền tố 1 chiều.

Nếu bộ cảm biến tín hiệu hoạt động ở tần số hàng trăm kHz, máy chủ phân tích sẽ sụp đổ ngay lập tức nếu liên tục lặp lại các vòng For đếm tay. Nhiệm vụ của bạn là hiện thực hóa thuật toán Mảng tiền tố nội suy, cho phép tra cứu cường độ tín hiệu chỉ trong $O(1)$ để đáp ứng yêu cầu Real-time của hệ thống.

**Yêu cầu:** Cho mảng $A$ gồm $N$ tín hiệu. Có $Q$ truy vấn, mỗi truy vấn yêu cầu tính tổng tín hiệu phát ra từ $L$ đến $R$. In ra kết quả trên từng dòng.

**Dữ liệu vào (Input):**

- Dòng đầu tiên chứa hai số nguyên dương $N, Q$.
- Dòng thứ hai chứa mảng $N$ phần tử.
- $Q$ dòng tiếp theo, mỗi dòng chứa cặp chỉ số $(L, R)$.

**Kết quả ra (Output):**

- In ra $Q$ dòng, mỗi dòng là tổng tích lũy của đoạn truy vấn.

**Ví dụ:**

| `BAI1.INP` | `BAI1.OUT` |
|:---|:---|
| `5 3` | `7` |
| `2 4 1 5 3` | `13` |
| `1 3` | `8` |
| `2 5` |  |
| `4 5` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N, Q \le 1000$.
- Subtask 2 (50% số điểm): $N, Q \le 2 \cdot 10^5$.

---

## MỨC ĐỘ 2: VẬN DỤNG CƠ BẢN

### Bài 2: XỬ LÝ DỮ LIỆU LOG CHUỖI NHIỀU KÝ TỰ (PREFIX SUM ON STRINGS)

**Tên file chương trình:** `BAI2.CPP` hoặc `BAI2.PY`
**File dữ liệu vào:** `BAI2.INP`
**File kết quả ra:** `BAI2.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [LeetCode 560: Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) / [CSES Task 1660: Subarray Sums I](https://cses.fi/problemset/task/1660).

Khi giải bài toán đếm các đoạn con liên tiếp có tổng không vượt quá $K$ (hoặc đúng bằng $K$), ta không thể chỉ phụ thuộc vào mảng tiền tố tĩnh. Khái niệm 'Kỹ thuật hai con trỏ' (Two Pointers / Sliding Window) được tích hợp song song với Mảng tiền tố, nơi hai con trỏ trượt trên mảng để thu hẹp hoặc mở rộng biên độ dò tìm.

Đối mặt với hàng triệu phần tử dữ liệu nén, một lập trình viên thiếu kinh nghiệm sẽ chọn cách dùng vòng lặp kép dẫn đến TLE. Sự kết tinh giữa mảng tiền tố và con trỏ trượt tạo ra giải thuật kỳ diệu quét qua toàn bộ mảng chỉ với đúng $O(N)$ thao tác vòng lặp duy nhất.

**Yêu cầu:** Cho mảng $A$ gồm $N$ số nguyên dương và số nguyên $K$. Đếm số lượng đoạn con liên tiếp sao cho tổng các phần tử trong đoạn bằng đúng $K$.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N$ và $K$.
- Dòng thứ hai chứa $N$ số nguyên âm dương đan xen.

**Kết quả ra (Output):**

- In ra số lượng đoạn con có tổng bằng $K$.

**Ví dụ:**

| `BAI2.INP` | `BAI2.OUT` |
|:---|:---|
| `5 7` | `3` |
| `2 4 1 2 7` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N \le 5000$.
- Subtask 2 (50% số điểm): $N \le 2 \cdot 10^5$.

---

## MỨC ĐỘ 3: VẬN DỤNG CẤU TRÚC ĐA CHIỀU

### Bài 3: TRÒ CHƠI DI CHUYỂN TỐI ƯU TRÊN ĐƯỜNG THẲNG (MINIMUM OPERATIONS)

**Tên file chương trình:** `BAI3.CPP` hoặc `BAI3.PY`
**File dữ liệu vào:** `BAI3.INP`
**File kết quả ra:** `BAI3.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [CSES Task 1652: Forest Queries (2D)](https://cses.fi/problemset/task/1652).

Vi xử lý hình ảnh y khoa nhận diện khối u qua các bức ảnh chụp CT (dưới dạng mảng 2D) thường phân hóa các điểm ảnh thành mức 0 (bình thường) và 1 (có bức xạ). Khái niệm Mảng Tiền Tố 2D giúp thuật toán phân tách và tính toán năng lượng của bất kỳ khối u (hình chữ nhật) nào trên ma trận một cách siêu tốc.

Tuy nhiên, bài toán này yêu cầu ứng dụng cả thuật toán nén hình ảnh Kadane 2D trên nền tảng Mảng tiền tố. Bạn cần xác định tọa độ vùng bức xạ lớn nhất trong thời gian cực ngắn để bác sĩ có thể can thiệp y khoa kịp thời.

**Yêu cầu:** Cho một ma trận $N \times M$. Tìm và in ra tổng lớn nhất của một hình chữ nhật con bất kỳ trong ma trận đó.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, M, Q$.
- $N$ dòng tiếp theo chứa ma trận 2D kích thước $N \times M$.
- $Q$ dòng tiếp theo, mỗi dòng chứa tọa độ $(r_1, c_1, r_2, c_2)$.

**Kết quả ra (Output):**

- In ra $Q$ dòng, mỗi dòng là tổng ma trận con tương ứng.

**Ví dụ:**

| `BAI3.INP` | `BAI3.OUT` |
|:---|:---|
| `3 3 2` | `12` |
| `1 2 3` | `28` |
| `4 5 6` |  |
| `7 8 9` |  |
| `1 1 2 2` |  |
| `2 2 3 3` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N, M \le 100, Q \le 1000$.
- Subtask 2 (50% số điểm): $N, M \le 1000, Q \le 2 \cdot 10^5$.

---

## MỨC ĐỘ 4: KHÁ - KHÓ (MẢNG HIỆU TUYẾN TÍNH)

### Bài 4: PHÂN BỔ CỎ KHÔ BẰNG MẢNG HIỆU 1D (DIFFERENCE ARRAY 1D)

**Tên file chương trình:** `BAI4.CPP` hoặc `BAI4.PY`
**File dữ liệu vào:** `BAI4.INP`
**File kết quả ra:** `BAI4.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [USACO 2012 Jan Bronze: Haybale Stacking](http://www.usaco.org/index.php?page=viewproblem2&cpid=104).

Trong kỹ thuật thi công đường sắt, việc nâng cấp một đoạn đường từ km thứ $L$ đến km thứ $R$ (ví dụ rải thêm $V$ tấn đá) diễn ra liên tục hàng ngày. Thuật toán Mảng hiệu 1D sẽ đánh dấu thay đổi ở đầu và cuối mỗi đoạn nâng cấp thay vì thay đổi toàn bộ chặng đường, giúp tiết kiệm triệt để tài nguyên tính toán.

Nếu các kỹ sư cập nhật từng mét vuông đất, thì hàng vạn thao tác sẽ tiêu tốn giới hạn hệ thống. Nhiệm vụ của bạn là sử dụng Mảng hiệu để gán điểm thay đổi cục bộ, và dùng Mảng tiền tố ở vòng lặp cuối cùng để khôi phục toàn vẹn bản thiết kế đường sắt.

**Yêu cầu:** Cho một đường sắt biểu diễn bằng mảng $A$ dài $N$, ban đầu gồm các số 0. Thực hiện $Q$ đợt nâng cấp, mỗi đợt cộng thêm $V$ từ vị trí $L$ đến $R$. In ra mảng $A$ hoàn chỉnh ở cuối cùng.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N$ và $Q$.
- $Q$ dòng tiếp theo mang số liệu cập nhật đoạn $L, R, V$.

**Kết quả ra (Output):**

- In ra mảng sau $Q$ thao tác cập nhật.

**Ví dụ:**

| `BAI4.INP` | `BAI4.OUT` |
|:---|:---|
| `5 3` | `2 3 3 4 4` |
| `1 3 2` |  |
| `2 5 1` |  |
| `4 5 3` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N, Q \le 1000$.
- Subtask 2 (50% số điểm): $N, Q \le 10^6$.

---

## MỨC ĐỘ 5: RẤT KHÓ (MẢNG HIỆU MA TRẬN 2D)

### Bài 5: MẠNG LƯỚI PHỤC HỒI KHÔNG GIAN (MẢNG HIỆU 2D - DIFFERENCE ARRAY 2D)

**Tên file chương trình:** `BAI5.CPP` hoặc `BAI5.PY`
**File dữ liệu vào:** `BAI5.INP`
**File kết quả ra:** `BAI5.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [LeetCode 2132: Stamping the Grid (2D Difference Array)](https://leetcode.com/problems/stamping-the-grid/) / [Luogu P3397: Carpet](https://www.luogu.com.cn/problem/P3397).

Cân bằng luồng khí lạnh trong các Data Center là bài toán quy hoạch 2D kinh điển. Khi một chiếc quạt gió tác động lên một vùng hình chữ nhật (cộng thêm $V$ độ C), thuật toán Mảng hiệu 2D sẽ thiết lập 4 điểm neo tại 4 góc của khu vực tác động. Đây là cấp độ cao nhất trong các loại cấu trúc tiền tố tĩnh.

Đối diện với hàng ngàn quạt gió công suất lớn biến thiên nhiệt độ liên tục, siêu máy tính chỉ có thể quản lý được bằng kỹ thuật nội suy Mảng hiệu 2D. Kết thúc các đợt làm lạnh, Mảng tiền tố 2D sẽ được kích hoạt để đưa ra bản đồ nhiệt độ cuối cùng một cách ngoạn mục.

**Yêu cầu:** Cho ma trận $A$ kích thước $N \times M$ ban đầu toàn số 0. Cập nhật $Q$ lần, mỗi lần cộng thêm $V$ độ vào toàn bộ khu vực từ góc $(r_1, c_1)$ đến $(r_2, c_2)$. Hãy in ra ma trận nhiệt độ tổng thể sau cùng.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, M, Q$.
- $Q$ dòng lệnh chứa 5 thông số $r_1, c_1, r_2, c_2, V$.

**Kết quả ra (Output):**

- Bản đồ địa hình 2D sau khi thực hiện tất cả $Q$ thao tác.

**Ví dụ:**

| `BAI5.INP` | `BAI5.OUT` |
|:---|:---|
| `3 3 2` | `1 1 0` |
| `1 1 2 2 1` | `1 3 2` |
| `2 2 3 3 2` | `0 2 2` |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N, M \le 100, Q \le 1000$.
- Subtask 2 (50% số điểm): $N, M \le 1000, Q \le 10^5$.

---
