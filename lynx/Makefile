#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=lynx
PKG_VERSION:=2.8.8rel.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://invisible-mirror.net/archives/lynx/tarballs
PKG_MD5SUM:=b231c2aa34dfe7ca25681ef4e55ee7e8

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)2-8-8

include $(INCLUDE_DIR)/package.mk

define Package/lynx
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libncursesw +libopenssl +zlib +libbz2 +libidn
	TITLE:=a text web browser
	URL:=http://lynx.isc.org/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/lynx/description
 Lynx is the text web browser
endef

CONFIGURE_ARGS += \
	--with-ssl \
	--enable-ipv6 \
	--with-screen=ncursesw \
	--enable-widec \
	--with-bzlib \
	--with-zlib \

define Package/lynx/conffiles
/opt/etc/lynx.cfg
/opt/etc/lynx.lss
endef

define Package/lynx/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lynx $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/lynx.cfg $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/samples/lynx.lss $(1)/opt/etc
endef

$(eval $(call BuildPackage,lynx))
