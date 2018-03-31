
<h1>Giới thiệu</h1>
<p>Trong phần đồ án này ta sẽ phối hợp các kĩ thuật, cấu trúc dữ liệu cơ bản và kiến thức lập
trình hướng đối tượng để xây dựng một trò chơi băng qua đường (road crossing).
Để thực hiện được đồ án này ta cần các kiến thức cơ bản như: xử lý tập tin, tiểu trình,
handle, các cấu trúc dữ liệu cơ bản và kiến thức lập trình hướng đối tượng…
Phần hướng dẫn giúp sinh viên xây dựng trò chơi ở mức độ cơ bản, các em tự nghiên cứu
để hoàn thiện một cách tốt nhất có thể. </p>
<h1>Kịch bản trò chơi</h1>
<p>
  <ul> 
    <li>Lúc đầu khi vào game sẽ xuất hiện các xe và thú chạy qua lại và một kí tự “Y” đại diện
        cho người qua đường, người chơi sử dụng các phím „W‟, „A‟, „S‟, „D‟ để điều chỉnh
        hướng di chuyển của người qua đường và cố gắng tránh các xe và thú. </li>
    <li> Khi “Y” va chạm các xe hay thú thì chương trình thông báo yêu cầu người chơi chọn
        phím „y‟ nếu muốn tiếp tục (chương trình sẽ thiết lập lại dữ liệu trò chơi lại như lúc ban
      đầu) hoặc chọn „bất kì phím nào‟ nếu muốn thoát trò chơi. </li>
    <li> Khi “Y” đi qua được hết các xe và thú thì sẽ lên cấp kế tiếp, độ khó của trò chơi chính là
      số lượng xe và thú tham gia di chuyển trên đường (Vị trí của “Y” mới sẽ xuất hiện trở lại
      khi lên cấp). Khi lên cấp tối đa nào đó thì dữ liệu sẽ khởi động lại như lúc ban đầu. </li>
  </ul>
</p>
