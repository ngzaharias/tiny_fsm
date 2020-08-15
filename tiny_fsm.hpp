#include <optional>
#include <variant>

namespace example
{
	struct Output;

	class StateA { public: void OnUpdate(Output& output); };
	class StateB { public: void OnUpdate(Output& output); };
	class StateC { public: void OnUpdate(Output& output); };

	using States = std::variant<StateA, StateB, StateC>;
	using Transition = std::optional<States>;

	struct Output
	{
	public:
		Transition transition;
	};
}