template <class T>
uint64_t Utils::generateId(const std::vector<T>& data)
{
	bool isFree;
	uint64_t id{ 0 };
	do
	{
		id = distribution(mersenneTwisterEngine);

		isFree = data.end() == std::ranges::find_if(data, [&id](const auto& el)
		{
			return id == el.getId();
		});
	} while (not isFree);

	return id;
}