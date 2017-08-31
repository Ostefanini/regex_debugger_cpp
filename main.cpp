#include <iostream>
// For cin/cout…
#include <regex>
// C++11 Regex facilities
#include <string>

static void		debug_submatch_infos(const std::ssub_match &first_sub,
					     const std::ssub_match &sub,
					     const size_t i)
{
  std::cout << "\t\tStart SubMatchInfos" << std::endl;
  std::cout << "\t\t\tsubmatch[" << i << "].distance = " << sub.length() << std::endl;
  if (sub.matched == true)
    std::cout << "\t\t\tsubmatch[" << i << "].match_state = MATCH :)" << std::endl;
  else
    std::cout << "\t\t\tsubmatch[" << i << "].matche_state = Not MATCH :/" << std::endl;
  std::cout << "\t\t\tsubmatch start = "<< std::distance(first_sub.first, sub.first) << std::endl;
  // Remember, first submatch is the same as global match.
  std::cout << "\t\t\tsubmatch end = "<< std::distance(first_sub.first, sub.second) << std::endl;
  std::cout << "\t\tEnd SubMatchInfos" << std::endl;
}

static void		debug_infos(const std::smatch &infos)
{
  size_t		i = 0;
  std::ssub_match	first_match = infos[0];

  std::cout << "\tStart MatchInfos" << std::endl;
  std::cout << "\t\tmatch.infos.empty() : " << std::boolalpha << infos.empty() << std::endl;
  std::cout << "\t\tmatch.infos.size() : " << infos.size() << std::endl;
  std::cout << "\t\tmatch.infos.length() = " << infos.length() << std::endl;
  while (i < infos.size())
    {
      debug_submatch_infos(first_match, infos[i], i);
      ++i;
    }
  std::cout << "\tEND MatchInfos" << std::endl;
}

static void		do_regex_match(const std::string &user_input,
				       const std::regex &regex)
{
  std::smatch		infos;

  std::cout << "START MatchState" << std::endl;
  if (regex_match(user_input, infos, regex))
    std::cout << "\tMaster match = Sucess ! :)" << std::endl;
  else
    std::cout << "\tMaster match = Fail ! :/" << std::endl;
  debug_infos(infos);
  std::cout << "END MatchState" << std::endl;
}

int			main()
{
  std::string		regex_str;
  std::string		user_input{""};
  std::regex		regex_rule;
  int			MatchId{0};

  std::cout << "Please, give me a regex in string running format" << std::endl;
  // Escaping different in code and in result of getline
  std::getline(std::cin, regex_str);
  regex_rule.assign(regex_str);
  // Default using ECMAScrip syntax
  while (true)
    {
      std::cout << "[" << MatchId << "]>" << std::flush;
      std::getline(std::cin, user_input);
      if (user_input == "quit" || user_input == "")
	return (0);
      do_regex_match(user_input, regex_rule);
      // Dump all informations using tabulations
      ++MatchId;
    }
  return (0);
}
