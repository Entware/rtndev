#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=lynx
PKG_VERSION:=2.8.9dev.19
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://invisible-mirror.net/archives/lynx/tarballs
PKG_HASH:=0223706f8310ecb738342c6bc51ebbe1879f2890a56c5e6f099e28289a8a8e9f

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/lynx
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libncursesw +libopenssl +zlib +libbz2 +libidn
	TITLE:=a text web browser
	URL:=http://lynx.isc.org/
	MAINTAINER:=Entware team, https://entware.net
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
	--with-build-cc=$(HOSTCC) \
	--with-build-cflags= \
	--with-build-ldflags=

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
