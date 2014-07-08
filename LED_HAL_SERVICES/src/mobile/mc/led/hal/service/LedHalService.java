package mobile.mc.led.hal.service;

public class LedHalService
{
	private static LedHalService ledHalService;

	public static LedHalService getInstance()
	{
		if (ledHalService == null)
		{
			return new LedHalService();
		} else
		{
			return ledHalService;
		}
	}

	private LedHalService()
	{
		init();
	}

	public void init()
	{
		_init();
	}

	/**
	 * setState(byte[]) Use a byte[4] to transmite led state
	 * 
	 * led:'1' means on and '0'means off
	 * 
	 * @param led
	 */
	public void setState(byte[] led)
	{
		_set_state(led);
	}

	// initial native method
	private native boolean _init();

	private native boolean _set_state(byte[] led);

	static
	{
		System.load("/system/lib/led_hal_jni.so");
	}
}