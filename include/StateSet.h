#pragma once
class StateSet
{
public:
	StateSet() {}
	~StateSet() {}

private:
	bool depth_test = true;
	bool stencil_test = false;
	bool blend = false;
};