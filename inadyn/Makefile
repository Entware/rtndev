#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=inadyn
PKG_VERSION:=2.1
PKG_RELEASE:=1

PKG_REV:=68563e3dee42089a98522a0fac7cb5049e473daa
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/troglobit/inadyn
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/inadyn
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=IP Addresses and Names
	DEPENDS:=+libite +confuse +libopenssl +ca-certificates
	TITLE:=a simple and small DDNS client
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/inadyn/description
 Inadyn is a simple and small DDNS client written in the C language. It can
 maintain multiple host names with the same IP address, and has a web based
 IP detection which runs well behind a NAT router. This is a fork by
 Andrey Tikhomirov.
endef

CONFIGURE_ARGS += --enable-openssl

TARGET_CFLAGS += -Iinclude

define Package/inadyn/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/var/cache/inadyn
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/inadyn $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/examples/custom.conf $(1)/opt/etc/inadyn.conf
	$(INSTALL_BIN) ./files/S52inadyn $(1)/opt/etc/init.d
endef

define Package/inadyn/conffiles
/opt/etc/inadyn.conf
endef

$(eval $(call BuildPackage,inadyn))
