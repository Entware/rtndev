# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=3proxy
PKG_VERSION:=1.0.0
PKG_REV:=f6963ea302bd01209dc94f8677c3dba9f3504b4e
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/z3APA3A/3proxy.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=75dec68df43f92d77b45de60975e963d7f1acfbdf14eb6525f60fa01f2c2c496

include $(INCLUDE_DIR)/package.mk

define Package/3proxy
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	DEPENDS:=+libpthread +libpcre2
	TITLE:=3proxy free proxy server
	URL:=http://www.3proxy.ru
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/3proxy/description
 3proxy is universal proxy server. It can be used to provide internal users
 with fully controllable access to external resources or to provide external
 users with access to internal resources.
 Note: SSL plugin requires libopenssl to be installed.
endef

define Package/3proxy/conffiles
/opt/etc/3proxy/3proxy.cfg
/opt/etc/3proxy/bandlimiters
/opt/etc/3proxy/counters
/opt/etc/3proxy/passwd
endef

define Build/Configure
	$(CP) $(PKG_BUILD_DIR)/Makefile.Linux $(PKG_BUILD_DIR)/Makefile
endef

MAKE_FLAGS += \
	PREFIX="" \
	CRYPT_PREFIX="my"

define Package/3proxy/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/bin/{3proxy,ftppr,mycrypt,pop3p,proxy,smtpp,socks,tcppm,udppm} \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib/3proxy
	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/bin/{Strings,Traffic,Transparent,File}Plugin.ld.so \
		$(1)/opt/lib/3proxy
	$(INSTALL_DIR) $(1)/opt/etc/3proxy
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/scripts/3proxy.cfg.in $(1)/opt/etc/3proxy/3proxy.cfg
	touch $(1)/opt/etc/3proxy/{passwd,counters,bandlimiters}
	chmod 0600 $(1)/opt/etc/3proxy/*
	$(CP) $(PKG_BUILD_DIR)/scripts/add3proxyuser.sh.in $(1)/opt/etc/3proxy/add3proxyuser.sh
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S23proxy $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,3proxy))
