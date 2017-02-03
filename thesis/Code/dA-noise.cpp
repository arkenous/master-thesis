/**
 * データごとに0.0以上1.0未満の乱数を生成し，rate未満であればそのデータを0.0にする
 * @param input ノイズをのせるデータ
 * @param rate ノイズをのせる確率
 * @return ノイズをのせたデータ
 */
vector<vector<double>> add_noise(const vector<vector<double>> &input, const float rate) {
  random_device rnd;
  mt19937 mt;
  mt.seed(rnd());
  uniform_real_distribution<double> real_rnd(0.0, 1.0);
  double rnd_value = 0.0;

  vector<vector<double>> result(input);

  for (unsigned long i = 0, i_s = result.size(); i < i_s; ++i) {
    double max = *std::max_element(result[i].begin(), result[i].end());
    double min = *std::min_element(result[i].begin(), result[i].end());
    for (unsigned long j = 0, j_s = result[i].size(); j < j_s; ++j) {
      rnd_value = real_rnd(mt);
      if (rnd_value < rate) {
        if (rnd_value < rate / 2) {
          result[i][j] = min;
        } else {
          result[i][j] = max;
        }
      }
    }
  }

  return result;
}
