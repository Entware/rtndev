#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=angband
PKG_VERSION:=4.2.5
PKG_RELEASE:=1

PKG_SOURCE:=Angband-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/angband/angband/releases/download/$(PKG_VERSION)
PKG_HASH:=c4cacbdf28f726fcb1a0b30b8763100fb06f88dbb570e955232e41d83e0718a6

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
	$(INSTALL_DIR) $(1)/opt/share/angband/{help,screens}
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/angband/help/*.txt $(1)/opt/share/angband/help
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/angband/screens/*.txt $(1)/opt/share/angband/screens
endef

$(eval $(call BuildPackage,angband))
