#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=asterisk18-chan-dongle
PKG_VERSION:=1.1-20150411
PKG_REV:=5263047a3d240b34b1776be0993ae0af01993823
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/bg111/asterisk-chan-dongle
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/asterisk18-chan-dongle
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Telephony
	DEPENDS:=+asterisk18 $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=Huawei UMTS 3G dongle support
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/asterisk18-chan-dongle/description
 Asterisk channel driver for Huawei UMTS cards.
 This channel driver is in alpha stage.
endef

CONFIGURE_ARGS += \
	--with-asterisk=$(STAGING_DIR)/opt/include/asterisk-1.8/include

TARGET_CFLAGS += \
	-DLOW_MEMORY \
	-D_XOPEN_SOURCE=600 \
	-DHAVE_CONFIG_H \

MAKE_ARGS += \
	DESTDIR="$(PKG_INSTALL_DIR)" \

define Package/asterisk18-chan-dongle/conffiles
/opt/etc/asterisk/dongle.conf
endef

define Package/asterisk18-chan-dongle/install
	$(INSTALL_DIR) $(1)/opt/etc/asterisk
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/etc/dongle.conf $(1)/opt/etc/asterisk/
	$(INSTALL_DIR) $(1)/opt/lib/asterisk/modules
	$(CP) $(PKG_BUILD_DIR)/chan_dongle.so $(1)/opt/lib/asterisk/modules/
endef

$(eval $(call BuildPackage,asterisk18-chan-dongle))
