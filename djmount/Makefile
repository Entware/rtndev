#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned since 2006, Debian patches applied

include $(TOPDIR)/rules.mk

PKG_NAME:=djmount
PKG_VERSION:=0.71
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)/$(PKG_NAME)/$(PKG_VERSION)
PKG_HASH:=aa5bb482af4cbd42695a7e396043d47b53d075ac2f6aa18a8f8e11383c030e4f

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/djmount
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libupnp +libfuse $(ICONV_DEPENDS) $(INTL_DEPENDS) +libtalloc
	TITLE:=mount MediaServers content as a Linux filesystem
	URL:=http://djmount.sourceforge.net
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/djmount/description
 djmount is a UPnP AV client. It mounts as a Linux filesystem the media content
 of compatible UPnP AV devices. Djmount discovers automatically all UPnP Media
 Servers on the network, and make the content available in a directory tree.
 All shared files (e.g. Audio or Video files) are directly visible and can be
 played using your favorite media player.
endef

CONFIGURE_ARGS += \
	--disable-debug \
	--with-libiconv-prefix=$(ICONV_PREFIX) \
	--with-external-libupnp \
	--with-libupnp-prefix=$(STAGING_DIR)/opt \

define Package/djmount/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/djmount $(1)/opt/bin/
endef

$(eval $(call BuildPackage,djmount))
