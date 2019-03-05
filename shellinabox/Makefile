#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Initial port of shellinabox to OpenWrt - Jan Jaeger 25-MAR-2010
# Makefile from OnionIoT/OpenWRT-Packages was used as a start

include $(TOPDIR)/rules.mk

PKG_NAME:=shellinabox
PKG_VERSION:=2.20
PKG_REV:=048cecd2e77d659c8fefcd2e7dc437c533abeab4
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/shellinabox/shellinabox.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/shellinabox
	SECTION:=net
	CATEGORY:=Network
	TITLE:=Shell In A Box
	DEPENDS:=+libopenssl
	URL:=https://github.com/shellinabox/shellinabox
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/shellinabox/description
 Web based AJAX terminal emulator
endef

CONFIGURE_ARGS += \
	--disable-pam \
	--disable-runtime-loading \
	--bindir="/opt/sbin"

define Package/shellinabox/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/shellinaboxd $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S88shellinaboxd $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/lib/shellinabox
	$(INSTALL_DATA) \
	    $(PKG_BUILD_DIR)/shellinabox/{black-on-white,color,monochrome,white-on-black}.css \
	    $(1)/opt/lib/shellinabox
endef

$(eval $(call BuildPackage,shellinabox))
