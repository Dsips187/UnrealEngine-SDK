#include "CPP_CreateWalletActor.h"
#include "Autogen/VyWalletAPI.h"

// Sets default values
ACPP_CreateWalletActor::ACPP_CreateWalletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_CreateWalletActor::BeginPlay()
{
	Super::BeginPlay();

	//The Request
	FVyCreateWalletRequest request{};
	request.Chain = EVyChain::MATIC;
	request.Pincode = TEXT("123456");
	request.Identifier = FVyOptString{ TEXT("Venly UE Wallet") };
	request.Description = FVyOptString{ TEXT("This is my first wallet!") };

	//Handler
	FVyOnCreateWalletComplete handler{};
	handler.BindLambda([](FVyCreateWalletResponse response)
		{
			if (response.Success) //Success!
			{
				auto msg = TEXT("[CPP] Wallet Created! addr=") + response.Result.Address;
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.f, FColor(0, 255, 0), msg);
			}
			else //Fail!
			{
				auto errMsg = response.Errors[0].Message;
				auto msg = TEXT("[CPP] Wallet Creation Failed! errMsg=") + errMsg;
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.f, FColor(255, 0, 0), msg);
			}
		});

	//Invoke!
	UVyWalletAPI::Get()->CreateWallet(request, handler);
}

// Called every frame
void ACPP_CreateWalletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

