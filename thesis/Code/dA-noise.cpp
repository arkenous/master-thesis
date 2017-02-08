vector<vector<double>> gaussian_noise(const vector<vector<double>> &input, const double mean, const double stddev, const float rate) {
  vector<vector<double>> result(input);
  random_device rnd;
  mt19937 mt;
  mt.seed(rnd());
  uniform_real_distribution<double> real_rnd(0.0, 1.0);
  std::normal_distribution<double> dist(mean, stddev);

  for (unsigned long i = 0, i_s = result.size(); i < i_s; ++i) {
    for (unsigned long j = 0, j_s = result[i].size(); j < j_s; ++j) {
      if (real_rnd(mt) <= rate) {
        result[i][j] += dist(mt);
      }
    }
  }

  return result;
}
