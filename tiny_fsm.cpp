#include "tiny_fsm.hpp"

void example::StateA::OnUpdate(example::Output& output)
{
	output.transition = States{ StateB() };
}

void example::StateB::OnUpdate(example::Output& output)
{
	output.transition = States{ StateC() };
}

void example::StateC::OnUpdate(example::Output& output)
{
	output.transition = States{ StateA() };
}

int main()
{
	example::States state = example::StateA();
	while (true)
	{
		auto transition = std::visit(
			[](auto& state) -> example::Transition
			{
				example::Output output;
				state.OnUpdate(output);
				return output.transition;
			}, state);

		if (transition)
		{
			state = transition.value();
		}
	}

	return 0;
}