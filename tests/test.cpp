// Copyright 2021 Denis <denis.gorbachev2002@yandex.ru>

#include <gtest/gtest.h>
#include <students.hpp>

TEST(Test1, parse_file) {
  Student one = {"Ivanov Petr", (std::string)"1", (std::string) "4.25", nullptr};
  Student two = {"Sidorov Ivan", (size_t)31, (size_t)4, (std::string)"C++" };
  std::vector<std::string> debts = {"C++", "Linux", "Network"};
  Student three = {"Petrov Nikita", (std::string)"IU8-31", (double)3.33,
                   (std::vector<std::string>)debts};
  std::vector<Student> students_1 = {one, two, three};
  std::stringstream ss1;
  print(students_1, ss1);

  auto text = R"(
{
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Petrov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  std::stringstream ss;
  ss << text;
  nlohmann::json data = json::parse(ss);
  std::vector<Student> students_2 = parse_file(data);
  std::stringstream ss2;
  print(students_2, ss2);

  ASSERT_EQ(ss1.str(), ss2.str());

}