// tasmota/tasmota_support/support_command.ino

void CmndTeleperiod(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload < 3601)) {
    Settings->tele_period = (1 == XdrvMailbox.payload) ? TELE_PERIOD : XdrvMailbox.payload;
    if ((Settings->tele_period > 0) && (Settings->tele_period < 2)) {
      Settings->tele_period = 2;   // Do not allow periods < 10 seconds
    }
  }
  TasmotaGlobal.tele_period = (Settings->tele_period) ? Settings->tele_period : 3601;  // Show teleperiod data also on empty command
  ResponseCmndNumber(Settings->tele_period);
}

