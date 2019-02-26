#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ps3netsrv
PKG_VERSION:=20150203
PKG_REV:=eaf2329d54e8231d4bfb1d8c8a19f7ea6848443c
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/dirkvdb/ps3netsrv--.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/ps3netsrv
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libstdcpp +libpthread
	TITLE:=C++ implementation of the ps3netsrv server
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ps3netsrv/description
 C++ implementation of the ps3netsrv server
endef

TARGET_LDFLAGS += \
	-lstdc++ \
	-lpthread

define Package/ps3netsrv/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ps3netsrv\+\+ $(1)/opt/sbin/ps3netsrv
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S76ps3netsrv $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/share/ps3netsrv/{GAMES,PS3ISO}
endef

$(eval $(call BuildPackage,ps3netsrv))
