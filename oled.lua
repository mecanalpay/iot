SDA = 6
SCL = 7

ADDRESS = 0x3c

i2c.setup(0, SDA, SCL, i2c.SLOW)

disp = u8g.ssd1306_128x64_i2c(ADDRESS)

function draw()
  disp:setFont(u8g.font_6x10)
  disp:drawStr(10, 10, "BUTECO OPEN SOURCE")
  disp:drawLine(0, 16, 128, 16);
  disp:setFont(u8g.font_chikita)
  disp:drawStr(38, 30, "Exemplo com")
  disp:drawStr(26, 40, "Display OLED I2C")
  disp:drawStr(40, 50, "no BUTECO")
end

function drawLoop()
  disp:firstPage()
  repeat
    draw()
  until disp:nextPage() == false
end

drawLoop()

