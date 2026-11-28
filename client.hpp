#pragma once
#include <string>
#include <string_view>
#include <memory>
#include "Zakaz.hpp"

class BaseClient
{
	private:
		static constexpr int MAX_LIMIT{ 2 };
		int m_activeCount{ 0 };
		std::string m_name{};

	protected:
		std::shared_ptr<Zakaz> m_zList[MAX_LIMIT]{};
		bool CheckAbility() const;
		int GetActiveCount() const;
		std::string_view GetName() const;
		void AddActiveCount();
		
	public:
		BaseClient();
		BaseClient(std::string_view);
		BaseClient(const BaseClient&);
		BaseClient(BaseClient&&) noexcept;
		BaseClient& operator=(const BaseClient&);
		BaseClient& operator=(BaseClient&&) noexcept;
		virtual ~BaseClient();
		virtual std::shared_ptr<Zakaz> MakeZakaz(int) = 0;
};

class FClient : public BaseClient
{
	public:
		FClient();
		FClient(std::string_view);
		FClient(const FClient&);
		FClient(FClient&&) noexcept;
		FClient& operator=(const FClient&);
		FClient& operator=(FClient&&) noexcept;
		~FClient() override;
		std::shared_ptr<Zakaz> MakeZakaz(int) override;
};

class UClient : public BaseClient
{
	public:
		UClient(std::string_view);
		std::shared_ptr<Zakaz> MakeZakaz(int) override;
};