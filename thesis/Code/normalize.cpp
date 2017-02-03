void normalize(vector<double> *input) {
  // 一つのセットにおける平均値を求める
  unsigned long input_size = (*input).size();
  double avg = 0;
  double sum = 0;
  for (int data = 0; data < input_size; ++data) sum += (*input)[data];
  avg = sum / input_size;
  // 偏差の二乗の総和を求める
  sum = 0;
  for (int data = 0; data < input_size; ++data) sum += pow(((*input)[data] - avg), 2);
  // 分散を求める
  double dispersion = sum / input_size;

  // 標準偏差を求める
  double standard_deviation = sqrt(dispersion);

  // 正規化し，得たデータで上書きする
  for (int data = 0; data < input_size; ++data)
    (*input)[data] = ((*input)[data] - avg) / standard_deviation;
}
