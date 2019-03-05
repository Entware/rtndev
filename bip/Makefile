#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bip
PKG_VERSION:=0.9.0-rc3-20181225
PKG_REV:=c9cc64f2e1932339ddd08d39261331f6b6ceee71
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://vcs-git.duckcorp.org/projects/bip/bip.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/bip
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Instant Messaging
	DEPENDS:=+libopenssl
	TITLE:=multi user irc proxy
	URL:=https://projects.duckcorp.org/projects/bip
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/bip/description
 Bip is an IRC proxy, which means it keeps connected to your preferred
 IRC servers, can store the logs for you, and even send them back to your
 IRC client(s) upon connection.
endef

define Package/bip/conffiles
/opt/etc/bip.conf
endef

define Package/bip/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/bip{,mkpw} $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) \
		$(PKG_INSTALL_DIR)/opt/share/doc/bip/examples/bip.conf \
		$(1)/opt/etc
	$(INSTALL_BIN) ./files/S99bip $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,bip))
