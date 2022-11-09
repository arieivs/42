# ifndef TARGET_GENERATOR_HPP
# define TARGET_GENERATOR_HPP

# include <vector>
# include "ATarget.hpp"

class TargetGenerator {
	public:
		TargetGenerator(void);
		~TargetGenerator(void);
	
		void		learnTargetType(ATarget* spell);
		void		forgetTargetType(std::string const & target_type);
		ATarget*	createTarget(std::string const & target_type);

	private:
		std::vector<ATarget*>	targets;

		TargetGenerator(TargetGenerator const & src);
		TargetGenerator&	operator=(TargetGenerator const & src);
};

#endif