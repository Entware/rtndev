#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=gnuchess
PKG_VERSION:=6.2.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@GNU/chess
PKG_HASH:=ddfcc20bdd756900a9ab6c42c7daf90a2893bf7f19ce347420ce36baebc41890

include $(INCLUDE_DIR)/package.mk

define Package/gnuchess
	SECTION:=games
	CATEGORY:=Games
	TITLE:=GNU Chess
	DEPENDS:=+libreadline +libncurses +libpthread +libstdcpp
	URL:=http://www.gnu.org/software/chess/chess.html
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/gnuchess/description
 GNU Chess lets most modern computers play a full game of chess.
 It has a plain terminal interface but supports visual interfaces such as XBoard.
endef

define Package/gnuchess/conffiles
/opt/share/gnuchess/gnuchess.ini
endef

define Package/gnuchess/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/gnuchess $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/gnuchess
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/src/smallbook.bin $(1)/opt/share/gnuchess
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/src/gnuchess.ini $(1)/opt/share/gnuchess
endef

$(eval $(call BuildPackage,gnuchess))
