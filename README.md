# Venly SDK for Unreal Engine 5

This repository contains the Venly SDK plugin for Unreal Engine 5. The plugin in not yet available on the marketplace, so it must be installed as a project plugin. This can easily be achieved by copying the required plugin folders into your project's plugin directory.

The repo consists out of multiple projects, each with their own purpose and specific dependencies. Each of these projects contain a sample level (API Explorer) showcasing some of the functionalities of the SDK.

1. **VenlySDK_UE** : Base Project hosting the Venly SDK plugin source (DevMode)
2. **VenlySDK_UE_Beamable** : Example project with Beamable as Backend Provider (Beamable)
3. **VenlySDK_UE_PlayFab** : Example project with PlayFab as Backend Provider (PlayFab)


The plugin can be used in **Blueprint-only Projects** and/or **Code Projects**.

&nbsp;

## Plugins & Dependencies

### >> VenlySDK_UE (/Plugins)

| Plugin | Description |
|--------|:-----------:|
| Venly  | Venly SDK Plugin Source |

&nbsp;

### >> VenlySDK_UE_Beamable (/Plugins)

| Plugin | Description |
|--------|:-----------:|
| Venly (SymLink)  | Venly SDK Plugin Source. (SymLink to VenlySDK_UE/Plugins/Venly) |
| BeamableCore  | Beamable SDK (Acquired from https://github.com/beamable/UnrealSDK) |
| VenlyBeamable  | Bridge between the Venly and Beamable SDK |

_note_: The **VenlyBeamable** plugin depends on both the **Venly** and **BeamableCore** Plugins

&nbsp;

### >> VenlySDK_UE_PlayFab (/Plugins)

| Plugin | Description |
|--------|:-----------:|
| Venly (SymLink)  | Venly SDK Plugin Source. (SymLink to VenlySDK_UE/Plugins/Venly) |
| PlayFab  | PlayFab SDK (Acquired from UE Marketplace) |
| VenlyPlayFab  | Bridge between the Venly and PlayFab SDK |

_note_: The **VenlyPlayFab** plugin depends on both the **Venly** and **PlayFab** Plugins

&nbsp;

## Documentation

[Docs & Guides](https://docs.venly.io/docs/getting-started-with-unreal-engine)\
[API Reference](https://sdk.venly.io/sdk-reference/ue5-sdk/function-reference)