# BÁO CÁO CHUYÊN MÔN: HỆ THỐNG BÀI TẬP BỒI DƯỠNG MẢNG TIỀN TỐ (20 BÀI)

## MỨC ĐỘ 1: CƠ BẢN (NHẬN BIẾT & THÔNG HIỂU)

### Bài 1: TỔNG ĐOẠN TĨNH CỦA CHUỖI CUNG ỨNG (STATIC RANGE SUM)

**Tên file chương trình:** `BAI1.CPP` hoặc `BAI1.PY`
**File dữ liệu vào:** `BAI1.INP`
**File kết quả ra:** `BAI1.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [CSES Task 1646: Static Range Sum Queries](https://cses.fi/problemset/task/1646).

Trong quản trị chuỗi cung ứng logistics, việc theo dõi lưu lượng hàng hóa là cốt lõi để tối ưu hóa quy trình. Khái niệm 'Mảng tiền tố' (Prefix Sum) được định nghĩa là một cấu trúc dữ liệu phụ trợ dùng để lưu trữ tổng tích lũy của các phần tử từ vị trí đầu tiên đến vị trí hiện tại. Cấu trúc này giúp giải quyết bài toán tra cứu tổng của một đoạn con bất kỳ trong mảng một cách tức thời.

Với một hệ thống thương mại điện tử có hàng triệu giao dịch, nếu sử dụng phương pháp cộng dồn thủ công bằng vòng lặp cho mỗi lần tra cứu, máy chủ sẽ nhanh chóng rơi vào trạng thái quá tải. Nhiệm vụ của bạn là phải thiết kế một thuật toán truy vấn tổng tối ưu và tinh tế hơn.

**Yêu cầu:** Cho một dãy gồm $N$ số nguyên dương biểu diễn khối lượng giao dịch trong $N$ ngày. Hãy trả lời $Q$ truy vấn, mỗi truy vấn tính tổng khối lượng giao dịch từ ngày $L$ đến ngày $R$.

**Dữ liệu vào (Input):**

- Dòng đầu tiên chứa hai số nguyên dương $N$ và $Q$.
- Dòng thứ hai chứa $N$ số nguyên biểu diễn mảng doanh thu.
- $Q$ dòng tiếp theo, mỗi dòng chứa hai chỉ số $L, R$.

**Kết quả ra (Output):**

- In ra $Q$ dòng, mỗi dòng là tổng doanh thu của đoạn tương ứng.

**Ví dụ:**

| `BAI1.INP` | `BAI1.OUT` |
|:---|:---|
| `5 3` | `7` |
| `2 4 1 5 3` | `13` |
| `1 3` | `8` |
| `2 5` |  |
| `4 5` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N, Q \le 10^3$.
- Subtask 2 (50% số điểm): $N, Q \le 2 \cdot 10^5$.

---

### Bài 2: KHẢO SÁT ĐIỂM CÂN BẰNG TRỌNG LỰC CẦU TREO (EQUILIBRIUM INDEX)

**Tên file chương trình:** `BAI2.CPP` hoặc `BAI2.PY`
**File dữ liệu vào:** `BAI2.INP`
**File kết quả ra:** `BAI2.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [LeetCode 724: Find Pivot Index](https://leetcode.com/problems/find-pivot-index/).

Cơ học tĩnh lực yêu cầu sự cân bằng trọng lực tuyệt đối ở các trụ cầu treo. Trong toán tin, 'Điểm cân bằng' (Equilibrium Index) được định nghĩa là một vị trí $i$ trong dãy số sao cho tổng các phần tử nằm bên trái vị trí $i$ bằng đúng tổng các phần tử nằm bên phải vị trí $i$. Tại vị trí này, giá trị của chính phần tử $i$ không được tính vào cả hai bên.

Đối với những cây cầu quy mô nhỏ, việc quét qua và tính tổng hai bên cho từng điểm neo là rất dễ dàng. Nhưng khi dải phân bổ mở rộng lên đến hàng trăm ngàn điểm neo, bài toán sẽ đòi hỏi một thuật toán Mảng tiền tố tối ưu tuyến tính để xác định điểm cân bằng mà không cần phải lặp lại vòng lặp lồng nhau.

**Yêu cầu:** Cho mảng số nguyên $A$ gồm $N$ phần tử biểu diễn trọng lượng tại các điểm neo. Hãy tìm và in ra vị trí cân bằng đầu tiên hợp lệ. Nếu không có vị trí nào thỏa mãn, in ra -1.

**Dữ liệu vào (Input):**

- Dòng đầu tiên chứa số lượng khối bê tông $N$.
- Dòng thứ hai chứa danh sách $N$ số nguyên mô tả trọng lượng.

**Kết quả ra (Output):**

- In ra vị trí cân bằng hợp lệ đầu tiên. Nếu không tồn tại điểm nào, in ra -1.

**Ví dụ:**

| `BAI2.INP` | `BAI2.OUT` |
|:---|:---|
| `6` | `4` |
| `1 7 3 6 5 6` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (40% số điểm): $N \le 10^4$. Các trọng lượng đều là số dương.
- Subtask 2 (60% số điểm): $N \le 2 \cdot 10^5$. Giá trị trọng lượng có thể nhận giá trị âm.

---

### Bài 3: PHỤC HỒI DỮ LIỆU BITWISE TUYẾN TÍNH (PREFIX XOR)

**Tên file chương trình:** `BAI3.CPP` hoặc `BAI3.PY`
**File dữ liệu vào:** `BAI3.INP`
**File kết quả ra:** `BAI3.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [CSES Task 1650: Static Range Xor Queries](https://cses.fi/problemset/task/1650).

Mã hóa và phục hồi dữ liệu là một trong những nền tảng quan trọng nhất của Mật mã học. Khi truyền tin qua môi trường nhiễu sóng, dữ liệu thường bị hỏng. Khái niệm 'Prefix XOR' (Tiền tố XOR) là việc áp dụng phép toán Bitwise XOR tĩnh lũy từ đầu mảng. Vì phép toán XOR có tính chất tự nghịch đảo ($A \oplus A = 0$), ta có thể trích xuất giá trị XOR của bất kỳ đoạn con nào bằng cách lấy phần tử tiền tố cuối đoạn XOR với phần tử tiền tố ngay trước đoạn.

Đối với các dải tín hiệu nhỏ, việc tính toán XOR từng bit rất đơn giản. Tuy nhiên, khi luồng tín hiệu truyền dẫn đạt dung lượng hàng trăm nghìn packet với hàng loạt các truy vấn liên tục, máy chủ sẽ yêu cầu một thuật toán nội suy XOR tối ưu $O(1)$ cho mỗi truy vấn.

**Yêu cầu:** Cho một dãy $N$ số nguyên biểu thị luồng tín hiệu. Hãy trả lời $Q$ truy vấn, mỗi truy vấn yêu cầu tính giá trị XOR tích lũy của mọi phần tử từ vị trí $L$ đến vị trí $R$.

**Dữ liệu vào (Input):**

- Dòng đầu tiên chứa $N$ và $Q$.
- Dòng thứ hai chứa $N$ số nguyên biểu thị trạng thái.
- $Q$ dòng tiếp theo chứa hai số nguyên giới hạn $L$ và $R$.

**Kết quả ra (Output):**

- In ra $Q$ dòng, mỗi dòng in ra giá trị đáp án độc lập cho một truy vấn.

**Ví dụ:**

| `BAI3.INP` | `BAI3.OUT` |
|:---|:---|
| `5 2` | `7` |
| `2 4 1 3 6` | `4` |
| `1 3` |  |
| `2 5` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (40% số điểm): $N, Q \le 10^3$.
- Subtask 2 (60% số điểm): $N, Q \le 2 \cdot 10^5$.

---

### Bài 4: PHÂN BỔ CỎ KHÔ BẰNG MẢNG HIỆU 1D (DIFFERENCE ARRAY 1D)

**Tên file chương trình:** `BAI4.CPP` hoặc `BAI4.PY`
**File dữ liệu vào:** `BAI4.INP`
**File kết quả ra:** `BAI4.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [USACO 2012 Jan Bronze: Haybale Stacking](http://www.usaco.org/index.php?page=viewproblem2&cpid=104).

Trong quản lý tài nguyên nông nghiệp diện rộng, việc cập nhật rải rác nguồn cung cấp diễn ra thường xuyên. 'Mảng hiệu' (Difference Array) được định nghĩa là một cấu trúc dữ liệu lưu trữ độ chênh lệch giữa phần tử hiện tại và phần tử ngay trước nó ($D[i] = A[i] - A[i-1]$). Bằng cách sử dụng mảng hiệu, ta có thể cập nhật cộng thêm một giá trị $V$ vào một đoạn từ $L$ đến $R$ chỉ bằng hai thao tác cục bộ thay vì phải lặp qua toàn bộ đoạn.

Với một nông trại gồm hàng triệu khoảnh đất, nếu cập nhật từng khoảnh một cách thủ công qua mỗi mệnh lệnh, hệ thống sẽ mất rất nhiều thời gian. Bài toán đòi hỏi một thuật toán kết hợp Mảng hiệu để đánh dấu điểm thay đổi, và sau đó dùng Mảng tiền tố để khôi phục lại trạng thái cuối cùng của toàn bộ nông trại.

**Yêu cầu:** Cho mảng $A$ ban đầu gồm $N$ phần tử đều bằng 0. Có $Q$ phép cập nhật, mỗi phép cộng thêm giá trị $V$ vào đoạn từ $L$ đến $R$. Hãy tính và in ra mảng $A$ sau khi thực hiện xong tất cả các phép cập nhật.

**Dữ liệu vào (Input):**

- Dòng đầu tiên chứa hai số $N, Q$.
- $Q$ dòng tiếp theo chứa 3 số $L, R, V$.

**Kết quả ra (Output):**

- In ra mảng $A$ sau $Q$ thao tác cập nhật, các phần tử cách nhau một khoảng trắng.

**Ví dụ:**

| `BAI4.INP` | `BAI4.OUT` |
|:---|:---|
| `5 3` | `2 3 3 4 4` |
| `1 3 2` |  |
| `2 5 1` |  |
| `4 5 3` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (30% số điểm): $N, Q \le 1000$.
- Subtask 2 (70% số điểm): $N, Q \le 10^6$.

---

### Bài 5: BẢNG PHÂN BỔ NHIỆT ĐỘ KHU VỰC 2D (PREFIX SUM 2D)

**Tên file chương trình:** `BAI5.CPP` hoặc `BAI5.PY`
**File dữ liệu vào:** `BAI5.INP`
**File kết quả ra:** `BAI5.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [CSES Task 1643: Maximum Subarray Sum](https://cses.fi/problemset/task/1643).

Trong Khí tượng học, việc theo dõi nhiệt độ trên các bản đồ vệ tinh dạng lưới đòi hỏi khả năng truy xuất dữ liệu vùng mạnh mẽ. 'Mảng tiền tố 2D' (2D Prefix Sum) được định nghĩa là một ma trận trong đó mỗi ô $(i, j)$ lưu trữ tổng của toàn bộ các phần tử trong hình chữ nhật có đỉnh góc trên trái là $(1, 1)$ và đỉnh góc dưới phải là $(i, j)$.

Khi cần thống kê tổng nhiệt lượng của các khu vực hình chữ nhật nhỏ lẻ trên toàn bộ bản đồ vệ tinh khổng lồ, kỹ thuật quét thủ công sẽ quét qua từng ô dẫn đến độ phức tạp $O(N^2)$ cho mỗi truy vấn. Điều này hoàn toàn bất khả thi. Nhiệm vụ của bạn là phải tính trước Mảng tiền tố 2D để có thể nội suy tổng của mọi khu vực chỉ với 4 phép toán cộng trừ.

**Yêu cầu:** Cho ma trận lưới $A$ kích thước $N \times M$. Có $Q$ truy vấn, mỗi truy vấn cung cấp tọa độ hai góc đối diện $(r_1, c_1)$ và $(r_2, c_2)$ của một hình chữ nhật. Hãy tính và in ra tổng các phần tử trong hình chữ nhật đó.

**Dữ liệu vào (Input):**

- Dòng đầu tiên chứa số nguyên $N$.
- Dòng thứ hai chứa $N$ số nguyên (có thể âm).

**Kết quả ra (Output):**

- In ra tổng đoạn con lớn nhất.

**Ví dụ:**

| `BAI5.INP` | `BAI5.OUT` |
|:---|:---|
| `8` | `9` |
| `-1 3 -2 5 3 -5 2 2` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N \le 10^3$.
- Subtask 2 (50% số điểm): $N \le 2 \cdot 10^5$.

---

## MỨC ĐỘ 2: TRUNG BÌNH (VẬN DỤNG CẤU TRÚC PHỨC HỢP)

### Bài 6: XỬ LÝ DỮ LIỆU LOG CHUỖI NHIỀU KÝ TỰ (PREFIX SUM ON STRINGS)

**Tên file chương trình:** `BAI6.CPP` hoặc `BAI6.PY`
**File dữ liệu vào:** `BAI6.INP`
**File kết quả ra:** `BAI6.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [LeetCode 560: Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) / [CSES 1660: Subarray Sums I](https://cses.fi/problemset/task/1660).

Trong lĩnh vực Phân tích Log hệ thống (System Logging), việc đếm nhanh sự xuất hiện của các mã lỗi cụ thể là vô cùng cấp thiết. Khái niệm 'Tiền tố tần suất' (Frequency Prefix Sum) mở rộng từ mảng số học sang dạng chuỗi hoặc mảng đếm tần suất. Theo đó, thay vì chỉ lưu tổng giá trị, mảng tiền tố sẽ lưu số lần xuất hiện của một giá trị (hoặc ký tự) cụ thể từ vị trí đầu tiên tới vị trí hiện tại.

Khi đối mặt với hàng tỷ dòng log hệ thống và cần tra cứu ngẫu nhiên số lượng lỗi nghiêm trọng ('E') trong các khung giờ bất kỳ, các hệ thống giám sát cần phản hồi trong vòng mili-giây. Bài toán yêu cầu vận dụng kỹ thuật cộng dồn tần suất để thống kê số lượng ký tự lỗi trong một đoạn mã chuỗi cho trước.

**Yêu cầu:** Cho một chuỗi ký tự $S$ có độ dài $N$ chỉ gồm các chữ cái in hoa. Có $Q$ truy vấn, mỗi truy vấn yêu cầu đếm số lần xuất hiện của một ký tự $X$ trong đoạn chuỗi từ vị trí $L$ đến vị trí $R$.

**Dữ liệu vào (Input):**

- Dòng đầu tiên chứa hai số nguyên $N$ và $K$.
- Dòng thứ hai chứa $N$ số nguyên (tần số dao động).

**Kết quả ra (Output):**

- In ra số lượng đoạn con thỏa mãn yêu cầu.

**Ví dụ:**

| `BAI6.INP` | `BAI6.OUT` |
|:---|:---|
| `5 7` | `3` |
| `2 4 1 2 7` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (40% số điểm): $N \le 5000$.
- Subtask 2 (60% số điểm): $N \le 2 \cdot 10^5$.

---

### Bài 7: ĐẾM SỐ LƯỢNG ĐOẠN CON CÓ TỔNG CHIA HẾT CHO K (SUBARRAY SUM DIVISIBLE BY K)

**Tên file chương trình:** `BAI7.CPP` hoặc `BAI7.PY`
**File dữ liệu vào:** `BAI7.INP`
**File kết quả ra:** `BAI7.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [LeetCode 974: Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/).

Lý thuyết số và Mật mã phân mảnh thường xuyên phải giải quyết các dạng toán liên quan đến tính chia hết. 'Đồng dư thức tiền tố' (Prefix Sum Modulo) kết hợp sức mạnh của mảng cộng dồn với thuật toán Bảng Băm (Hash Map). Theo nguyên lý Dirichlet, nếu hai điểm tiền tố $i$ và $j$ có cùng số dư khi chia cho $K$, thì tổng của đoạn con từ $(i+1)$ đến $j$ chắc chắn sẽ chia hết cho $K$.

Nếu duyệt tất cả các cặp điểm $(i, j)$ trên mảng kích thước hàng trăm ngàn, giới hạn thời gian chạy 1.0 giây sẽ không cho phép. Đòi hỏi một thuật toán tinh tế hơn: Duy trì một bảng băm đếm số lần xuất hiện của từng phần dư khi quét mảng tiền tố để đạt độ phức tạp tuyến tính $O(N)$.

**Yêu cầu:** Cho mảng số nguyên $A$ gồm $N$ phần tử và một số nguyên dương $K$. Hãy tìm và in ra số lượng đoạn con (các phần tử liên tiếp) có tổng chia hết cho $K$.

**Dữ liệu vào (Input):**

- Dòng đầu tiên chứa hai số nguyên $N$ và $K$.
- Dòng thứ hai chứa chuỗi $N$ phần tử số nguyên.

**Kết quả ra (Output):**

- In ra số lượng đoạn con có tổng chia hết cho $K$.

**Ví dụ:**

| `BAI7.INP` | `BAI7.OUT` |
|:---|:---|
| `6 5` | `7` |
| `4 5 0 -2 -3 1` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (40% số điểm): $N \le 5000$.
- Subtask 2 (60% số điểm): $N \le 2 \cdot 10^5$.

---

### Bài 8: TRÒ CHƠI DI CHUYỂN TỐI ƯU TRÊN ĐƯỜNG THẲNG (MINIMUM OPERATIONS)

**Tên file chương trình:** `BAI8.CPP` hoặc `BAI8.PY`
**File dữ liệu vào:** `BAI8.INP`
**File kết quả ra:** `BAI8.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [CSES Task 1074: Stick Lengths (Minimum Operations)](https://cses.fi/problemset/task/1074) / [CSES Task 1652: Forest Queries (2D)](https://cses.fi/problemset/task/1652).

Tối ưu hóa tài nguyên trong Khoa học máy tính thường liên quan đến việc thu gom các đối tượng về một điểm hội tụ chung. 'Đường đi tối ưu' dựa trên mảng tiền tố giúp tính toán nhanh tổng khoảng cách từ các điểm vệ tinh về một trung tâm định trước. Khi kết hợp mảng tiền tố để tra cứu tổng vị trí, ta có thể triệt tiêu việc phải duyệt lại toàn bộ các điểm cần di chuyển.

Giả sử bạn phải điều hướng hàng chục ngàn xe tự lái về một điểm tập kết trên xa lộ. Để tính chi phí nhiên liệu tối thiểu trong thời gian thực, thuật toán cần khả năng tính toán chênh lệch khoảng cách tuyệt đối. Thay vì tính khoảng cách từng xe, hãy sử dụng tính chất mảng tiền tố để cộng gộp hàng loạt.

**Yêu cầu:** Cho mảng $A$ chứa tọa độ ban đầu của $N$ chiếc xe tự lái, đã được sắp xếp tăng dần. Hãy tìm một điểm tập kết chung sao cho tổng khoảng cách di chuyển của tất cả các xe là nhỏ nhất, và in ra tổng khoảng cách tối thiểu đó.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, M, Q$.
- $N$ dòng tiếp theo, mỗi dòng $M$ số biểu diễn lưới 2D.
- $Q$ dòng tiếp theo, mỗi dòng chứa 4 số nguyên $r_1, c_1, r_2, c_2$.

**Kết quả ra (Output):**

- In ra $Q$ kết quả tổng nhiệt lượng tương ứng trên các dòng tách biệt.

**Ví dụ:**

| `BAI8.INP` | `BAI8.OUT` |
|:---|:---|
| `3 4 2` | `12` |
| `1 2 3 0` | `28` |
| `4 5 6 1` |  |
| `7 8 9 2` |  |
| `1 1 2 2` |  |
| `2 2 3 3` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (30% số điểm): $N, M \le 100, Q \le 1000$.
- Subtask 2 (70% số điểm): $N, M \le 1000, Q \le 2 \cdot 10^5$.

---

### Bài 9: MẠNG LƯỚI PHỤC HỒI KHÔNG GIAN (MẢNG HIỆU 2D - DIFFERENCE ARRAY 2D)

**Tên file chương trình:** `BAI9.CPP` hoặc `BAI9.PY`
**File dữ liệu vào:** `BAI9.INP`
**File kết quả ra:** `BAI9.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [LeetCode 2132: Stamping the Grid (2D Difference Array)](https://leetcode.com/problems/stamping-the-grid/) / [Luogu P3397: Carpet](https://www.luogu.com.cn/problem/P3397).

Đồ họa máy tính (Computer Graphics) ứng dụng rất nhiều phép biến đổi ảnh raster. 'Mảng hiệu 2D' (2D Difference Array) là phiên bản nâng cấp mạnh mẽ nhất của cấu trúc mảng hiệu, cho phép cập nhật cộng thêm giá trị $V$ vào toàn bộ một vùng hình chữ nhật. Thay vì phải cộng từng ô pixels, ta chỉ cần đặt 4 điểm neo tại 4 góc của vùng chữ nhật đó.

Khi người dùng áp dụng hàng loạt các bộ lọc (filters) tăng giảm độ sáng lên một bức ảnh độ phân giải $4K$, thuật toán ngây thơ sẽ khiến máy tính bị treo vì phải cập nhật hàng chục triệu pixel lặp đi lặp lại. Bạn phải vận dụng Mảng hiệu 2D để ghi nhận các điểm neo thay đổi, sau đó khôi phục bức ảnh chung cuộc bằng kỹ thuật Mảng tiền tố 2D.

**Yêu cầu:** Cho ma trận $A$ kích thước $N \times M$ ban đầu toàn số 0. Thực hiện $Q$ thao tác, mỗi thao tác cộng thêm $V$ vào tất cả các ô trong hình chữ nhật từ góc $(r_1, c_1)$ đến $(r_2, c_2)$. Hãy in ra ma trận cuối cùng.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, M, Q$.
- $Q$ dòng tiếp theo chứa 5 thông số độc lập: $r_1, c_1, r_2, c_2, V$.

**Kết quả ra (Output):**

- In ra $N$ dòng, mỗi dòng $M$ số nguyên biểu diễn ma trận kết quả.

**Ví dụ:**

| `BAI9.INP` | `BAI9.OUT` |
|:---|:---|
| `3 3 2` | `1 1 0` |
| `1 1 2 2 1` | `1 3 2` |
| `2 2 3 3 2` | `0 2 2` |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (30% số điểm): $N, M \le 100, Q \le 1000$.
- Subtask 2 (70% số điểm): $N, M \le 1000, Q \le 2 \cdot 10^5$.

---

### Bài 10: MẬT MÃ MẢNG NHỊ PHÂN CÂN BẰNG (MAXIMUM BALANCED SUBARRAY)

**Tên file chương trình:** `BAI10.CPP` hoặc `BAI10.PY`
**File dữ liệu vào:** `BAI10.INP`
**File kết quả ra:** `BAI10.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [LeetCode 525: Contiguous Array (Maximum Balanced Subarray)](https://leetcode.com/problems/contiguous-array/).

Trong kiểm tra chẵn lẻ truyền thông tin (Parity Check), việc tìm kiếm các chuỗi dữ liệu có trạng thái cân bằng hoàn hảo là vô cùng phổ biến. Khái niệm 'Mảng biến đổi' quy định: để tìm mảng con có số lượng số 0 bằng số lượng số 1, ta biến toàn bộ số 0 thành -1. Khi đó, bài toán chuyển về việc tìm đoạn con dài nhất có tổng chính xác bằng 0.

Với chuỗi dữ liệu nhị phân hàng trăm ngàn bit, việc đếm thủ công các đoạn con sẽ dẫn đến bùng nổ tổ hợp. Bạn cần kết hợp linh hoạt giữa kỹ thuật Mảng tiền tố và Bảng Băm (Hash Map) lưu trữ vị trí đầu tiên của từng giá trị tổng tích lũy. Thuật toán này đòi hỏi sự tinh tế về mặt phân bổ bộ nhớ.

**Yêu cầu:** Cho một mảng $A$ độ dài $N$ chỉ gồm các phần tử 0 và 1. Hãy tìm và in ra độ dài của đoạn con liên tiếp dài nhất có số lượng số 0 bằng đúng số lượng số 1.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, Q, P$.
- Dòng thứ hai chứa mảng $N$ phần tử.
- $Q$ dòng tiếp theo, mỗi dòng chứa $L, R$.

**Kết quả ra (Output):**

- In ra $Q$ dòng, mỗi dòng chứa kết quả phép nhân modulo $P$.

**Ví dụ:**

| `BAI10.INP` | `BAI10.OUT` |
|:---|:---|
| `4 2 1000000007` | `24` |
| `2 3 4 5` | `60` |
| `1 3` |  |
| `2 4` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N, Q \le 5000$.
- Subtask 2 (50% số điểm): $N, Q \le 10^5$.

---

## MỨC ĐỘ 3: KHÁ - KHÓ (KỸ THUẬT NÂNG CAO)

### Bài 11: BƯỚC NHẢY VŨ TRỤ (FROG JUMP / PREFIX DP)

**Tên file chương trình:** `BAI11.CPP` hoặc `BAI11.PY`
**File dữ liệu vào:** `BAI11.INP`
**File kết quả ra:** `BAI11.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [AtCoder DP Contest: Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a) / [CSES Task 1633: Dice Combinations](https://cses.fi/problemset/task/1633).

Trong cơ học lượng tử hoặc lý thuyết trò chơi, bài toán tính toán số con đường khả dĩ để đạt đến một trạng thái thường được giải quyết bằng Quy hoạch động. Khái niệm 'Mảng tiền tố trên mảng DP' ra đời để tối ưu hóa việc tra cứu tổng các trạng thái trước đó. Thay vì duyệt lại toàn bộ các bước sóng trước đó, ta dùng một biến hoặc mảng tiền tố để lưu trữ tổng các phương án tính đến hiện tại.

Nếu một hạt vật chất có thể nhảy với bước sóng từ $L$ đến $R$, việc tính số cách di chuyển bằng 2 vòng lặp sẽ tiêu tốn giới hạn phần cứng vô nghĩa. Bằng cách thiết lập mảng tiền tố linh hoạt, độ phức tạp được đưa từ $O(N \times (R-L))$ xuống $O(N)$, thể hiện sự tinh tế tuyệt đỉnh của giải thuật.

**Yêu cầu:** Cho $N$ điểm dừng. Từ điểm $i$, bạn có thể nhảy tới điểm $j$ nếu $i+L \le j \le i+R$. Tính số cách để đi từ điểm 1 đến điểm $N$, kết quả lấy phần dư cho $10^9+7$.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, A, B$.
- Dòng hai chứa $N$ số nguyên mảng tài sản.

**Kết quả ra (Output):**

- In ra tổng cực đại đạt được.

**Ví dụ:**

| `BAI11.INP` | `BAI11.OUT` |
|:---|:---|
| `5 2 3` | `8` |
| `-1 3 -2 5 3` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N \le 5000$.
- Subtask 2 (50% số điểm): $N \le 2 \cdot 10^5$.

---

### Bài 12: CHỈ SỐ TĂNG TRƯỞNG TRUNG BÌNH (AVERAGE GROWTH RATE)

**Tên file chương trình:** `BAI12.CPP` hoặc `BAI12.PY`
**File dữ liệu vào:** `BAI12.INP`
**File kết quả ra:** `BAI12.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [VNOJ: Dãy con dài nhất (qbseq)](https://oj.vnoi.info/problem/qbseq).

Trong phân tích chứng khoán, việc tìm kiếm một chu kỳ thời gian có tốc độ tăng trưởng trung bình vượt qua ngưỡng kỳ vọng là một bài toán kinh điển. Để loại bỏ phép chia trung bình phức tạp, ta dùng kỹ thuật 'Mảng tiền tố định chuẩn': Trừ tất cả các phần tử trong mảng cho ngưỡng kỳ vọng $K$. Bài toán khi đó biến đổi thành việc tìm đoạn con có tổng tích lũy lớn hơn hoặc bằng 0.

Với lịch sử giao dịch lên đến hàng năm, số lượng bản ghi là quá lớn để quét mọi chu kỳ có thể có. Việc áp dụng Mảng tiền tố kết hợp với cây Fenwick Tree hoặc phương pháp chia để trị (Merge Sort) là bắt buộc để có thể đếm chính xác số lượng chu kỳ thỏa mãn trong giới hạn 1.0 giây.

**Yêu cầu:** Cho mảng $A$ độ dài $N$ đại diện cho chỉ số tăng trưởng hàng ngày và một số nguyên $K$. Hãy đếm số lượng đoạn con có giá trị trung bình cộng lớn hơn hoặc bằng $K$.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, K$.
- Dòng thứ hai chứa mảng $N$ phần tử.

**Kết quả ra (Output):**

- In ra số lượng đoạn con thỏa mãn.

**Ví dụ:**

| `BAI12.INP` | `BAI12.OUT` |
|:---|:---|
| `5 3` | `7` |
| `2 4 1 5 3` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (40% số điểm): $N \le 5000$.
- Subtask 2 (60% số điểm): $N \le 2 \cdot 10^5$.

---

### Bài 13: CHUỖI ADN XẾP HẠNG HỢP LỆ (VALID DNA SEQUENCE)

**Tên file chương trình:** `BAI13.CPP` hoặc `BAI13.PY`
**File dữ liệu vào:** `BAI13.INP`
**File kết quả ra:** `BAI13.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [LeetCode 327: Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/).

Phân tích tin sinh học (Bioinformatics) yêu cầu xử lý các dải ADN dạng chuỗi ngoặc `(` và `)`. Một chuỗi được xem là hợp lệ nếu ở bất kỳ vị trí nào, số lượng ngoặc mở luôn lớn hơn hoặc bằng số lượng ngoặc đóng, và tổng kết thúc phải cân bằng. Kỹ thuật Mảng tiền tố ánh xạ `(` thành $+1$ và `)` thành $-1$ là nền tảng cốt lõi của lý thuyết này.

Để tìm chiều dài của chuỗi ADN con hợp lệ dài nhất giữa hàng triệu đoạn gen không hoàn chỉnh, việc kiểm tra bằng Stack tốn quá nhiều tài nguyên hệ thống. Thay vào đó, việc dùng Mảng tiền tố để đánh dấu mức năng lượng, kết hợp cùng các cấu trúc lưu trữ chỉ mục nhỏ nhất sẽ mang lại tốc độ xử lý như vũ bão.

**Yêu cầu:** Cho một chuỗi $S$ độ dài $N$ chỉ gồm các ký tự `(` và `)`. Hãy tìm và in ra độ dài của chuỗi con liên tiếp dài nhất tạo thành một biểu thức ngoặc hợp lệ.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, K$.
- Dòng hai chứa mảng $N$ phần tử.

**Kết quả ra (Output):**

- In ra số lượng đoạn con có tổng nhỏ hơn $K$.

**Ví dụ:**

| `BAI13.INP` | `BAI13.OUT` |
|:---|:---|
| `4 5` | `6` |
| `1 2 3 -1` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (40% số điểm): $N \le 5000$.
- Subtask 2 (60% số điểm): $N \le 10^5$.

---

### Bài 14: GIA TỐC GRADIENT TRÊN MẢNG HIỆU (DIFFERENCE OF DIFFERENCE)

**Tên file chương trình:** `BAI14.CPP` hoặc `BAI14.PY`
**File dữ liệu vào:** `BAI14.INP`
**File kết quả ra:** `BAI14.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [Codeforces 295A: Greg and Array (Difference Array 2nd Order)](https://codeforces.com/contest/295/problem/A).

Khi các bài toán không chỉ dừng lại ở việc cộng một hằng số $V$, mà cộng các giá trị tăng dần theo cấp số cộng (ví dụ: cộng $1, 2, 3\dots$ vào đoạn $L \dots R$), Mảng hiệu bậc 1 trở nên bất lực. Chúng ta phải định nghĩa 'Mảng hiệu bậc 2' (Difference of Difference) – tức là đạo hàm bậc hai của mảng ban đầu. Các thao tác cập nhật khi đó được phân rã thành các điểm neo trên mảng hiệu bậc 2.

Trong vật lý mô phỏng gia tốc rơi tự do của các hạt, việc lập trình cập nhật tuyến tính cho từng mô phỏng là thảm họa. Bạn phải dùng kỹ thuật Mảng hiệu bậc 2 để gán 4 điểm neo gia tốc, sau đó chạy 2 lần Mảng tiền tố (lấy tích phân 2 lần) để khôi phục lại quỹ đạo cuối cùng của hệ thống.

**Yêu cầu:** Cho mảng $A$ ban đầu gồm $N$ số 0. Thực hiện $Q$ truy vấn, mỗi truy vấn cung cấp khoảng $L, R$ và yêu cầu cộng lần lượt $1, 2, 3\dots$ vào các vị trí từ $L$ đến $R$. In ra mảng $A$ sau $Q$ thao tác.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, Q$.
- $Q$ dòng tiếp theo chứa $L, R, D$.

**Kết quả ra (Output):**

- In ra mảng sau $Q$ thao tác cập nhật.

**Ví dụ:**

| `BAI14.INP` | `BAI14.OUT` |
|:---|:---|
| `5 2` | `2 3 3 1 1` |
| `1 3 2` |  |
| `2 5 1` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N, Q \le 1000$.
- Subtask 2 (50% số điểm): $N, Q \le 10^5$.

---

### Bài 15: KHOẢNG CÁCH MANHATTAN TỐI ƯU TRÊN LƯỚI (MANHATTAN DISTANCE)

**Tên file chương trình:** `BAI15.CPP` hoặc `BAI15.PY`
**File dữ liệu vào:** `BAI15.INP`
**File kết quả ra:** `BAI15.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [CodeChef: Sum of Manhattan Distances (SUMMAN)](https://www.codechef.com/problems/SUMMAN).

Trong bài toán quy hoạch đô thị, khoảng cách di chuyển giữa hai giao lộ trên hệ thống lưới đường vuông góc được gọi là 'Khoảng cách Manhattan' ($|x_1 - x_2| + |y_1 - y_2|$). Để tối ưu hóa việc tính toán tổng khoảng cách này, một thủ thuật kinh điển là biến đổi trục tọa độ: Xoay hệ tọa độ đi 45 độ bằng phép chuyển đổi $(X, Y) \to (x+y, x-y)$.

Với phép chuyển đổi kỳ diệu này, khoảng cách Manhattan phức tạp được tách thành hai bài toán khoảng cách độc lập trên hai trục 1 chiều (Chebyshev distance). Khi đó, Mảng tiền tố sẽ phô diễn sức mạnh bằng cách tính tổng khoảng cách 1 chiều chỉ trong chớp mắt, giải quyết triệt để nút thắt cổ chai của hệ thống.

**Yêu cầu:** Cho tọa độ của $N$ điểm trên mặt phẳng. Hãy tính tổng khoảng cách Manhattan giữa tất cả các cặp điểm $(i, j)$ với $1 \le i < j \le N$.

**Dữ liệu vào (Input):**

- Dòng đầu chứa số $N$.
- Dòng hai chứa mảng $A$ gồm $N$ số.

**Kết quả ra (Output):**

- In ra một số nguyên duy nhất là kết quả.

**Ví dụ:**

| `BAI15.INP` | `BAI15.OUT` |
|:---|:---|
| `3` | `20` |
| `1 2 3` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N \le 5000$.
- Subtask 2 (50% số điểm): $N \le 10^6$.

---

## MỨC ĐỘ 4: RẤT KHÓ (THI ĐẤU QUỐC GIA / IOI)

### Bài 16: TÁI CÂN BẰNG NĂNG LƯỢNG HẠT NHÂN (REBALANCING ENERGY)

**Tên file chương trình:** `BAI16.CPP` hoặc `BAI16.PY`
**File dữ liệu vào:** `BAI16.INP`
**File kết quả ra:** `BAI16.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [VNOJ: Robot Cleaner 2 (vnoicup24_r1_a)](https://oj.vnoi.info/problem/vnoicup24_r1_a).

Trong kỹ thuật hạt nhân, việc duy trì mức năng lượng của các thanh nhiên liệu ổn định là vô cùng cấp bách. Một thanh có thể truyền năng lượng cho thanh bên cạnh để cân bằng, mỗi đơn vị truyền đi tiêu tốn 1 mức chi phí. Bài toán đưa về việc tìm một điểm cân đối lý tưởng dựa trên trung vị (Median) của dãy.

Nếu chỉ tính điểm trung vị là chưa đủ, hệ thống cần tính nhanh tổng chi phí luân chuyển từ tất cả các thanh về mức trung vị. Kỹ thuật Mảng tiền tố kết hợp phân bổ mảng đã sắp xếp là chiếc chìa khóa vạn năng giúp thực thi lệnh truy vấn tối ưu luân chuyển năng lượng với tốc độ phần nghìn giây.

**Yêu cầu:** Cho $N$ kho chứa năng lượng với các mức nhiên liệu khác nhau. Trong mỗi bước, bạn có thể chuyển 1 đơn vị năng lượng sang kho kề cạnh. Hãy tính số bước di chuyển ít nhất để đưa năng lượng tất cả các kho về một mức cân bằng bằng nhau.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N$.
- Dòng hai chứa mảng $A$ gồm $N$ phần tử.

**Kết quả ra (Output):**

- In ra tổng lớn nhất của 2 đoạn con không giao nhau.

**Ví dụ:**

| `BAI16.INP` | `BAI16.OUT` |
|:---|:---|
| `7` | `12` |
| `1 -2 3 5 -1 4 -5` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (40% số điểm): $N \le 5000$.
- Subtask 2 (60% số điểm): $N \le 10^5$.

---

### Bài 17: KHAI PHÁ VÙNG QUẶNG KHÔNG GIAN K (SUBMATRIX SUM EQUALS K)

**Tên file chương trình:** `BAI17.CPP` hoặc `BAI17.PY`
**File dữ liệu vào:** `BAI17.INP`
**File kết quả ra:** `BAI17.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [LeetCode 1074: Number of Submatrices That Sum to Target](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/).

Trong kỹ thuật khai phá dữ liệu địa chất, bản đồ phân bổ khoáng sản được số hóa thành các lưới ma trận 2D. Các máy quét yêu cầu đếm số lượng khu vực hình chữ nhật (các vùng quặng) có tổng trữ lượng đúng bằng một ngưỡng $K$ thiết lập trước.

Thuật toán ngây thơ duyệt qua 4 điểm giới hạn của hình chữ nhật trên ma trận $N \times M$ sẽ đẩy hệ thống vào độ phức tạp $O(N^2 \times M^2)$, không thể ứng dụng trong thực tế. Đòi hỏi bạn phải áp dụng kỹ thuật 'Cố định 2 cạnh ngang' kết hợp mảng tiền tố 1D và Bảng băm (Hash Map) nén dữ liệu, giảm độ phức tạp xuống chỉ còn $O(N^2 \times M)$ để hệ thống quét hoàn thành.

**Yêu cầu:** Cho ma trận số nguyên $A$ kích thước $N \times M$ và một số nguyên $K$. Hãy tìm và đếm số lượng hình chữ nhật con trong ma trận có tổng các phần tử bằng đúng $K$.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, M, K$.
- $N$ dòng tiếp theo chứa lưới tọa độ $M$ phần tử.

**Kết quả ra (Output):**

- In ra số lượng lưới con 2D thỏa mãn.

**Ví dụ:**

| `BAI17.INP` | `BAI17.OUT` |
|:---|:---|
| `2 2 0` | `2` |
| `0 1` |  |
| `1 0` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N, M \le 50$.
- Subtask 2 (50% số điểm): $N, M \le 200$.

---

### Bài 18: SỰ KIỆN ĐỘNG LỰC LƯỚI BẰNG FENWICK TREE (OFFLINE BIT/FENWICK)

**Tên file chương trình:** `BAI18.CPP` hoặc `BAI18.PY`
**File dữ liệu vào:** `BAI18.INP`
**File kết quả ra:** `BAI18.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [Kattis ICPC Archive: Fenwick Tree](https://open.kattis.com/problems/fenwick).

Khi giải quyết các bài toán về luồng dữ liệu liên tục có đan xen giữa cập nhật điểm và truy vấn tổng đoạn, cấu trúc dữ liệu tĩnh như Mảng tiền tố bị vô hiệu hóa. Tuy nhiên, bằng kỹ thuật 'Offline Queries' (Lưu trữ toàn bộ truy vấn), ta có thể kết hợp Mảng tiền tố với Cây Fenwick (Binary Indexed Tree) để biến đổi các truy vấn phức tạp thành các thao tác đếm đơn giản.

Đối với một máy chủ xử lý hàng triệu gói tin vừa đến vừa bị thay đổi giá trị, xử lý trực tiếp từng gói tin là không thể. Bài toán yêu cầu bạn phải phân tích tĩnh toàn bộ hệ thống bằng việc phân rã truy vấn, sắp xếp lại dòng thời gian (Offline) và rải các điểm quét bằng Fenwick Tree cực kì điêu luyện.

**Yêu cầu:** Cho mảng $A$ gồm $N$ số nguyên dương. Có $Q$ truy vấn thuộc hai loại: (1) Cập nhật giá trị tại vị trí $i$ thành $v$; (2) Tính tổng các phần tử từ vị trí $L$ đến $R$. Yêu cầu xử lý và in ra kết quả cho các truy vấn loại 2.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, M, Q$ (tương thích Mảng hiệu 2D/1D).
- Các dòng tiếp theo mang tham số cập nhật bán kính lưới tọa độ Manhattan.

**Kết quả ra (Output):**

- In ra mảng sau $Q$ thao tác.

**Ví dụ:**

| `BAI18.INP` | `BAI18.OUT` |
|:---|:---|
| `3 3 1` | `0 5 0` |
| `2 2 1 5` | `5 5 5` |
|  | `0 5 0` |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (50% số điểm): $N \le 50$.
- Subtask 2 (50% số điểm): $N \le 1000$.

---

### Bài 19: RANH GIỚI LÃNH THỔ CỰC ĐẠI (MAX SUBARRAY DIFFERENCE)

**Tên file chương trình:** `BAI19.CPP` hoặc `BAI19.PY`
**File dữ liệu vào:** `BAI19.INP`
**File kết quả ra:** `BAI19.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [Codeforces 295A: Greg and Array (Difference Array)](https://codeforces.com/problemset/problem/295/A).

Phân tích xung đột lãnh thổ dựa trên nguyên lý mảng hiệu để tạo các ranh giới tăng cường. Bài toán yêu cầu không chỉ cộng một đoạn, mà phải xác định độ lệch cực đại giữa hai điểm bất kỳ sau khi một loạt các yếu tố môi trường đã tác động (cập nhật).

Thông qua một mảng hiệu ảo, bài toán thách thức tư duy của lập trình viên về cách vận hành cấu trúc dữ liệu linh hoạt. Nếu áp dụng cấu trúc dữ liệu khổng lồ như Segment Tree, chi phí bộ nhớ sẽ bị quá tải. Thay vào đó, việc dùng Mảng hiệu 1D chạy qua hai chiều ngược xuôi sẽ cho ra một giải pháp thanh lịch đến ngỡ ngàng.

**Yêu cầu:** Cho mảng $A$ gồm $N$ phần tử. Có $Q$ thao tác cộng thêm $V$ vào đoạn $L \dots R$. Sau khi thực hiện xong, hãy tìm chênh lệch lớn nhất giữa hai phần tử bất kỳ trong mảng cuối cùng.

**Dữ liệu vào (Input):**

- Dòng đầu chứa $N, Q$.
- $Q$ dòng cập nhật đoạn $[L, R]$ với giá trị $V$.

**Kết quả ra (Output):**

- Mảng sau khi đã cập nhật.

**Ví dụ:**

| `BAI19.INP` | `BAI19.OUT` |
|:---|:---|
| `5 2` | `2 3 3 1 0` |
| `1 3 2` |  |
| `2 4 1` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (100% số điểm): $N, Q \le 10^5$.

---

### Bài 20: KỶ NGUYÊN BĂNG GIÁ TUYỆT ĐỐI (CÂY PHÂN ĐOẠN LƯỠI LIỀM / SEGMENT TREE)

**Tên file chương trình:** `BAI20.CPP` hoặc `BAI20.PY`
**File dữ liệu vào:** `BAI20.INP`
**File kết quả ra:** `BAI20.OUT`
**Thời gian chạy giới hạn:** 1.0 giây

**Nguồn tham khảo:** [CSES Task 1735: Range Updates and Sums](https://cses.fi/problemset/task/1735).

Đỉnh cao của chuyên đề tối ưu hóa đoạn con chính là việc hợp nhất Mảng tiền tố với 'Cây Phân Đoạn Lưỡi Liềm' (Lazy Propagation Segment Tree). Khi bài toán đòi hỏi phải phản hồi kết quả truy vấn tổng Mảng ngay lập tức trong khi hệ thống vẫn đang liên tục tiếp nhận hàng loạt lệnh cập nhật đoạn, các phép toán mảng thông thường hoàn toàn sụp đổ.

Chỉ có những kỹ sư thuật toán xuất sắc nhất mới có thể xây dựng nên một cấu trúc cây đồng bộ hóa trễ (Lazy), giúp phân tán sức mạnh của Mảng tiền tố lên các nhánh của cây. Qua đó, mọi truy vấn cập nhật mảng hay tính tổng đoạn trong kỷ nguyên băng giá này đều được duy trì vững vàng ở độ phức tạp logarit $O(\log N)$.

**Yêu cầu:** Cho mảng $A$ độ dài $N$. Thực hiện $Q$ truy vấn xen kẽ. Có hai loại lệnh: (1) Cộng thêm $V$ vào tất cả phần tử từ $L$ đến $R$; (2) In ra tổng của tất cả các phần tử từ đoạn $X$ đến $Y$. Hệ thống phải in ra kết quả tương ứng ngay sau mỗi lệnh loại 2.

**Dữ liệu vào (Input):**

- Dòng đầu chứa số $N$.
- Dòng thứ hai chứa mảng $A$.

**Kết quả ra (Output):**

- In ra số lượng phương án xóa hợp lệ.

**Ví dụ:**

| `BAI20.INP` | `BAI20.OUT` |
|:---|:---|
| `4` | `1` |
| `2 1 6 4` |  |


**Giới hạn dữ liệu (Subtasks):**

- Subtask 1 (40% số điểm): $N \le 5000$.
- Subtask 2 (60% số điểm): $N \le 2 \cdot 10^5$.

---
