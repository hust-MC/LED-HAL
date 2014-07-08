package mobile.mc.ledhal_app;

import mobile.mc.led.hal.service.LedHalService;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;

public class MainActivity extends Activity
{
	CheckBox[] checkBoxs = new CheckBox[4];
	LedHalService ledHalService = LedHalService.getInstance();
	byte[] led = {'0','0','0','0'};
	
	public void widget_init()
	{
		checkBoxs[0] = (CheckBox) findViewById(R.id.led1);
		checkBoxs[1] = (CheckBox) findViewById(R.id.led2);
		checkBoxs[2] = (CheckBox) findViewById(R.id.led3);
		checkBoxs[3] = (CheckBox) findViewById(R.id.led4);
	}

	public void onClick_set(View view)
	{
		for (int i = 0; i < 4; i++)
		{
			if (checkBoxs[i].isChecked())
			{
				led[i] = 1;
			}
			else
			{
				led[i] = 0;
			}
		}
		ledHalService.setState(led);
	}

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		widget_init();
	}
}
