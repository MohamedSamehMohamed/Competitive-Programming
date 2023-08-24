class ChipRace
{
  vector<double> chances(vector<int> c)
  {
    vector<double> ret(c.size(), 0);
    int sum = 0;
    for (int i = 0; i < c.size(); i++)sum += c[i];
    int R = round( (1.0*sum * 5)/25 );
    vector<bool> take(c.size());
    for (int j = 1; j <= R; j++)
    {
      sum = 0;
      for (int i = 0; i < c.size(); i++)
      {
        if (take[i])continue;
        sum += c[i];
      }
      for (int i = 0; i < c.size(); i++)
      {
        if (take[i])continue;
        ret[i] += 1.0*c[i]/sum;
      }
    }
    for (auto i: ret)cout << i << " "; cout <<"\n";
    return ret;
  }
};
