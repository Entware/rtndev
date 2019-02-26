#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# No longer maintained. Origin was removed according to regulations.

include $(TOPDIR)/rules.mk

PKG_NAME:=shadowsocksr-libev
PKG_VERSION:=2.5.6-20170803
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_RELEASE).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/shadowsocksr-backup/shadowsocksr-libev.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=e2373d7199102f383b741da148b989c7c1e8832e

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/shadowsocksr-libev
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	DEPENDS:=+libopenssl +libpcre +libpthread
	TITLE:=libev port of ShadowsocksR
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/shadowsocksr-libev/description
 libev port of ShadowsocksR.
endef

CONFIGURE_ARGS += \
	--disable-documentation \
	--disable-ssp \
	--disable-assert

define Package/shadowsocksr-libev/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/ss-local $(1)/opt/bin/ssr-local
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/ss-redir $(1)/opt/bin/ssr-redir
endef

$(eval $(call BuildPackage,shadowsocksr-libev))
