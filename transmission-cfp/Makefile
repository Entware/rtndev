#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=transmission-cfp
PKG_VERSION:=2.77plus-20190205
PKG_REV:=c9896d1384e9b6cfdcee28871fc77c62cbe4c3fa
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/cfpp2p/transmission.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/transmission-cfp/Default
  SUBMENU:=BitTorrent
  SECTION:=net
  CATEGORY:=Network
  TITLE:=BitTorrent client
  URL:=https://github.com/cfpp2p/transmission
  MAINTAINER:=Entware team, https://entware.net
endef

define Package/transmission-cfp-daemon
$(call Package/transmission-cfp/Default)
  TITLE+= (daemon)
  DEPENDS:=+libcurl +libevent2 +zlib +USE_UCLIBC:libpthread +USE_UCLIBC:librt
endef

define Package/transmission-cfp-cli
$(call Package/transmission-cfp/Default)
  TITLE+= (cli)
  DEPENDS:=+libcurl +libevent2 +zlib +USE_UCLIBC:libpthread +USE_UCLIBC:librt
endef

define Package/transmission-cfp-remote
$(call Package/transmission-cfp/Default)
  TITLE+= (remote control utility)
  DEPENDS:=+libcurl +libevent2 +zlib +USE_UCLIBC:libpthread +USE_UCLIBC:librt
endef

define Package/transmission-cfp-web
$(call Package/transmission-cfp/Default)
  TITLE+= (webinterface)
  DEPENDS:=+transmission-cfp-daemon
endef

define Package/transmission-cfp-daemon/description
 Transmission is a simple BitTorrent client.
 It features a very simple, intuitive interface
 on top on an efficient, cross-platform back-end.
 This package contains the daemon itself.
endef

define Package/transmission-cfp-cli/description
 CLI utilities for transmission.
endef

define Package/transmission-cfp-remote/description
 CLI remote interface for transmission.
endef

define Package/transmission-cfp-web/description
 Webinterface resources for transmission.
endef

define Download/transmission-cfp-web-client
  FILE:=transmission-cfp-web-client-$(PKG_VERSION).tar.bz2
  URL:=$(PKG_SOURCE_URL)
  PROTO:=git
  VERSION:=f104a68aa2a5b76914cdebaf7ded7ba09defd23b
  SUBDIR:=transmission-cfp-web-client-$(PKG_VERSION)
endef
$(eval $(call Download,transmission-cfp-web-client))

define Build/Prepare
	$(call Build/Prepare/Default)
	$(TAR) -C $(PKG_BUILD_DIR) -xjf $(DL_DIR)/transmission-cfp-web-client-$(PKG_VERSION).tar.bz2 --strip-components=1
	chmod +x $(PKG_BUILD_DIR)/third-party/miniupnp/updateminiupnpcstrings.sh
	chmod +x $(PKG_BUILD_DIR)/update-version-h.sh
endef

define Build/Configure
	(cd $(PKG_BUILD_DIR) && ./update-version-h.sh)
	$(call Build/Configure/Default)
endef

CONFIGURE_ARGS += \
	--enable-utp \
	--enable-lightweight \
	--enable-cli \
	--enable-daemon \

define Package/transmission-daemon-openssl/conffiles
/opt/etc/transmission/settings.json
endef

define Package/transmission-cfp-daemon/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/transmission-daemon \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) files/S88transmission-cfp $(1)/opt/etc/init.d
	$(INSTALL_DIR) \
		$(1)/opt/etc/transmission/{blocklists,resume,torrents,watchdir}
	$(INSTALL_CONF) files/settings.json $(1)/opt/etc/transmission
endef

define Package/transmission-cfp-cli/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/opt/bin/transmission-{cli,create,edit,show} \
		$(1)/opt/bin
endef

define Package/transmission-cfp-remote/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/transmission-remote \
		$(1)/opt/bin
endef

define Package/transmission-cfp-web/install
	$(INSTALL_DIR) $(1)/opt/share/transmission/web
	$(CP) $(PKG_BUILD_DIR)/web-client-cfp/* \
		$(1)/opt/share/transmission/web
endef

$(eval $(call BuildPackage,transmission-cfp-daemon))
$(eval $(call BuildPackage,transmission-cfp-cli))
$(eval $(call BuildPackage,transmission-cfp-remote))
$(eval $(call BuildPackage,transmission-cfp-web))
