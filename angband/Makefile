#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=angband
PKG_VERSION:=4.1.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://rephial.org/downloads/4.1
PKG_HASH:=9402c4f8da691edbd4567a948c5663e1066bee3fcb4a62fbcf86b5454918406f

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk

define Package/angband
	SECTION:=games
	CATEGORY:=Games
	DEPENDS:=+libncursesw
	TITLE:=single-player, text-based, dungeon simulation game
	URL:=http://rephial.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/angband/description
 Angband is a single-player, text-based, dungeon simulation derived from
 the game Moria, which was in turn based on Rogue. It is often described
 as a \"roguelike\" game because the look and feel of the game is still
 quite similar to Rogue.
endef

CONFIGURE_ARGS += \
	--disable-x11 \
	--with-private-dirs \

define Package/angband/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/angband $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/angband/{customize,gamedata}
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/etc/angband/customize/*.prf $(1)/opt/etc/angband/customize
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/etc/angband/gamedata/*.txt $(1)/opt/etc/angband/gamedata
	$(INSTALL_DIR) $(1)/opt/share/angband/{help,screens,user/info}
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/angband/help/*.{txt,hlp} $(1)/opt/share/angband/help
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/angband/screens/*.txt $(1)/opt/share/angband/screens
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/angband/user/info/*.{txt,hlp} $(1)/opt/share/angband/user/info
endef

$(eval $(call BuildPackage,angband))
