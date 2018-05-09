#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=microdc2
PKG_VERSION:=0.15.6-20130828
PKG_RELEASE:=1

PKG_REV:=30bd14bdf0d58d3818cf4135ae8d689f01924590
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/jnwatts/microdc2
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/microdc2
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=P2P
	DEPENDS:=+libxml2 +libreadline +libncurses
	TITLE:=microdc2
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/microdc2/description
 A command-line based Direct Connect client.
endef

MAKE_FLAGS += \
	LTLIBICONV=""

define Package/microdc2/conffiles
/opt/share/microdc2/config
endef

define Package/microdc2/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{microdc2,tthsum} $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/share/microdc2
	$(INSTALL_CONF) ./files/microdc2.conf $(1)/opt/share/microdc2/config
endef

$(eval $(call BuildPackage,microdc2))
