#pragma once

class m_IDirectSoundFXWavesReverb8 : public IDirectSoundFXWavesReverb8, public AddressLookupTableDsoundObject
{
private:
	LPDIRECTSOUNDFXWAVESREVERB8 ProxyInterface;

public:
	m_IDirectSoundFXWavesReverb8(LPDIRECTSOUNDFXWAVESREVERB8 pSound8) : ProxyInterface(pSound8)
	{
		ProxyAddressLookupTableDsound.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectSoundFXWavesReverb8()
	{
		ProxyAddressLookupTableDsound.DeleteAddress(this);
	}

	LPDIRECTSOUNDFXWAVESREVERB8 GetProxyInterface() { return ProxyInterface; }

	// IUnknown methods
	STDMETHOD(QueryInterface)(THIS_ _In_ REFIID, _Outptr_ LPVOID*);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	// IDirectSoundFXWavesReverb methods
	STDMETHOD(SetAllParameters)(THIS_ _In_ LPCDSFXWavesReverb pcDsFxWavesReverb);
	STDMETHOD(GetAllParameters)(THIS_ _Out_ LPDSFXWavesReverb pDsFxWavesReverb);
};
